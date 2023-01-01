// Simple Socket program

#include <iostream>
#include <string>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>

using namespace std;

class ServerSocket {
    private:
        int _socketfd;
        int _portNumber;
        int _addressFamily;

        inline void throwLastError() {
            string scoketError(strerror(errno));
            throw scoketError;
        }

        void initSocketDes() {
            if( _socketfd != -1 ) close(_socketfd);

            _socketfd = socket(_addressFamily, SOCK_STREAM, 0);
            if( _socketfd < 0 ) throwLastError();
        }

        void bindToAnyAddress() {
            sockaddr_in serverAddress;
            bzero((char*)&serverAddress, sizeof(serverAddress));

            serverAddress.sin_family = AF_INET;
            serverAddress.sin_port = htons(_portNumber);
            serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

            int bindStatus = bind(_socketfd,
                (struct sockaddr*)&serverAddress,
                sizeof(serverAddress)
            );

            if( bindStatus < 0 ) throwLastError();            
        }

    public:
        ServerSocket(int portNum) {
            _portNumber = portNum;
            _addressFamily = AF_INET;
            _socketfd = -1;

            initSocketDes();
            bindToAnyAddress();
        }

        ~ServerSocket() {
            if( _socketfd != -1 ) close(_socketfd);
        }
};

int main(int argc, char* argv[]) {
    if( argc < 3 ) {
        cout << argv[0] << " <mode> <port>\n";
        return 0;
    }

    string programMode(argv[1]);
    int portNumber = atoi(argv[2]);

    // This actually perfoms the bind operation
    ServerSocket servSock(portNumber);

    portNumber = 0;
    cout << "Server running on the port " << portNumber << endl;
    cin >> portNumber;

    cout << "Shutting down the server\n";
    return 0;
}
