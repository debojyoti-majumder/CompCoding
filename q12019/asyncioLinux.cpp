// Ref link https://fwheel.net/aio.html

#include <fcntl.h>
#include <iostream>
#include <errno.h>
#include <aio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

using namespace std;


class LinuxFileDescriptor {
    private:
        int _descriptor;
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

        friend class AsyncRequest;
        friend class SyncFileStream;
};

class AsyncRequest {
    private:
        aiocb _blockRequest;
        int _blockSize;

    public:
        AsyncRequest(const LinuxFileDescriptor& desp, int blockSize) {
            memset(&_blockRequest, 0 , sizeof(aiocb));
            
            // Setting up the requets
            _blockRequest.aio_nbytes = blockSize;
            _blockRequest.aio_fildes = desp._descriptor;
            _blockRequest.aio_buf = new char[blockSize];

            _blockSize = blockSize;
        }

        ~AsyncRequest() {
        }

        void enQueueRead(int blockNumber) {
            _blockRequest.aio_offset = _blockSize * blockNumber;
            auto ret = aio_read(&_blockRequest);

            if( ret == -1 )
                throw "Read request creation error";
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

int main(int argc, char** argv) {
    const int blockSize = 512;
    
    // Ensuring command line parameter
    if( argc < 2 ) {
        cout << "Usage: " << argv[0] << " <filename>"; 
        return 0;
    }

    LinuxFileDescriptor file(argv[1]);
    AsyncRequest req(file, 512);
    SyncFileStream sreq(file);

    while( sreq.read() );
    cout << "Read count " << sreq.getCount() << endl;
    return 0;
}
