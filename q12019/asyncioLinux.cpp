// Ref link https://fwheel.net/aio.html

// Linux specific headers
#include <fcntl.h>
#include <errno.h>
#include <aio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

// CPP headers
#include <iostream>
#include <chrono>
#include <sstream>
#include <vector>
#include <thread>

using namespace std;


class LinuxFileDescriptor {
    private:
        int _descriptor;

        struct stat getStat() const {
            struct stat fileStatistics;
            auto ret = ::fstat(_descriptor, &fileStatistics);

            if( ret == -1 )
                throw "Unable to get stats";

            return fileStatistics;
        }

    public:
        LinuxFileDescriptor(char* strFileName, int mode = O_RDONLY) {
            _descriptor = open(strFileName, mode, 0);
            if( _descriptor == -1 ) {
                throw "File open error";
            }
        }

        ~LinuxFileDescriptor() {
            close(_descriptor);
        }

        size_t getSize() const {
            auto fdata (getStat());
            return fdata.st_size;
        }

        size_t getBlockCount() const {
            auto fdata(getStat());
            return fdata.st_blocks;
        }

        size_t getBlockSize() const {
            auto fdata(getStat());
            return fdata.st_blocks;
        }

        friend class AsyncRequest;
        friend class SyncFileStream;
};

class AsyncRequest {
    private:
        aiocb _blockRequest;
        int _blockSize;

        void setupBuffer() {
            // Setting up the requets
            _blockRequest.aio_nbytes = _blockSize;
            _blockRequest.aio_buf = new char[_blockSize];
        }

    public:
        // Block size is given by user
        AsyncRequest(const LinuxFileDescriptor& desp, int blockSize) {
            memset(&_blockRequest, 0 , sizeof(aiocb));

            _blockSize = blockSize;
            _blockRequest.aio_fildes = desp._descriptor;
            
            setupBuffer();
        }

        // Block size is determoned automatically
        AsyncRequest(const LinuxFileDescriptor& fd) {
            memset(&_blockRequest, 0 , sizeof(aiocb));
            
            _blockSize = fd.getBlockSize();            
            _blockRequest.aio_fildes = fd._descriptor;

            setupBuffer();
        }

        ~AsyncRequest() {
        }

        void enQueueRead(int blockNumber) {
            _blockRequest.aio_offset = _blockSize * blockNumber;
            auto ret = aio_read(&_blockRequest);

            if( ret == -1 )
                throw "Read request creation error";
        }

        bool isCompleted() const {
            return aio_error(&_blockRequest) == 0 ? true : false;
        }
};

class SyncFileStream {
    private:
        const LinuxFileDescriptor& _fd;
        int _blockSize;
        int _count;
    public:
        SyncFileStream(const LinuxFileDescriptor& fd) : _fd(fd) {
            _blockSize = 512;
            _count = 0;
        }

        bool read() {
            auto buff = new char[_blockSize];

            auto ret = ::read(_fd._descriptor, buff,_blockSize);
            if( ret == 0 )
                return false;

            _count++;
            delete[] buff;

            return true;
        }

        int getCount() const { return _count; }
};

void doSyncTest(char* fileName) {
    LinuxFileDescriptor file(fileName);
    SyncFileStream sreq(file);

    while( sreq.read() );
    cout << "Read count " << sreq.getCount() << endl;
}

void processReadRequests(vector<AsyncRequest>& readRequets, int offset = 0) {

    // Initiates the I/O request
    for(size_t i=0; i<readRequets.size(); i++) {
        readRequets[i].enQueueRead(i + offset);
    }

    auto doneCount = 0;
    while(doneCount < readRequets.size() ) {
        this_thread::sleep_for(std::chrono::milliseconds(10));
        for(auto& rec: readRequets) {
            if( rec.isCompleted() ) doneCount++;
        }
    }
}

void doAsyncTest(char* filename) {
    LinuxFileDescriptor file(filename);
    auto blCount = file.getBlockCount();
    const int buffCount = 500;
    auto iterations = blCount / buffCount;

    for(auto i=0; i<iterations; i++) {
        vector<AsyncRequest> readRequets;
        
        // Allocates the memory for the operation
        for(size_t blockNumber = 0; blockNumber < buffCount; blockNumber++ ) {
            readRequets.emplace_back(AsyncRequest{file});
        }

        processReadRequests(readRequets, i * buffCount);
        cout << i << " of " << iterations << endl;
    }
    
}

int main(int argc, char** argv) {
    const int blockSize = 512;
    chrono::nanoseconds syncDuration, asyncDuration;

    // Ensuring command line parameter
    if( argc < 2 ) {
        cout << "Usage: " << argv[0] << " <filename>"; 
        return 0;
    }

    // Measuing sync operation
    //{
    //    auto startTime = chrono::high_resolution_clock::now();
    //    doSyncTest(argv[1]);
    //    auto endTime = chrono::high_resolution_clock::now();
    //    syncDuration = endTime - startTime;
    //    cout << "Sync Clock count:" << syncDuration.count() << endl;
    //}

    // Measuing async opearion
    {
        auto startTime = chrono::high_resolution_clock::now();
        doAsyncTest(argv[1]);
        auto endTime = chrono::high_resolution_clock::now();
        asyncDuration = endTime - startTime;
        cout << "ASync Clock count:" << asyncDuration.count() << endl;

    }

    cout << "Main Diff: " << syncDuration.count() - asyncDuration.count() << endl;
    return 0;
}
