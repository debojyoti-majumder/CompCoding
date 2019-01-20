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
};

class AsyncRequest {
    private:
        aiocb _blockRequest;

    public:
        AsyncRequest(int blockSize, const LinuxFileDescriptor& desp, long blockCount) {
            memset(&_blockRequest, 0 , sizeof(aiocb));
            
            // Setting up the requets
            _blockRequest.aio_nbytes = blockSize;
            _blockRequest.aio_fildes = desp._descriptor;
            _blockRequest.aio_offset = blockSize * blockCount;
            _blockRequest.aio_buf = new char[blockSize];
        }

        ~AsyncRequest() {
            delete[] _blockRequest.aio_buf;
        }

        void read() {

        }
};

int main(int argc, char** argv) {
    const int blockSize = 512;
    
    // Ensuring command line parameter
    if( argc < 2 ) {
        cout << "Usage: " << argv[0] << " <filename>"; 
        return 0;
    }

    LinuxFileDescriptor file(argv[1]);
    AsyncRequest req(512,file,0);

    return 0;
}
