#include <iostream>
#include <memory>

using namespace std;

struct INetworkInterface {
    virtual void sendData(const string&) = 0;
    virtual string getData() = 0; 
    virtual ~INetworkInterface() {}
};

class EthernetNetwork : public INetworkInterface {
    private:
        string _m;

    public:
        void sendData(const string& msg) override {
            _m = msg;
            _m += "Through wire";

            cout << "Sending data through earth and metal" << endl; 
        }

        string getData() override {
            return _m;
        } 

        ~EthernetNetwork() {
            cout << "Clean up task for ethernet" << endl;
        }
};

class WifiNetwork : public INetworkInterface {
    private:
    public:
        void sendData(const string& msg) override {
            cout << msg << endl;
        }

        string getData() override {
            string m{"hardcoded"};

            return m;
        }

        ~WifiNetwork() {
            cout << "Clean up task for wifi" << endl;
        }
}; 

void sendMessage(INetworkInterface* const ptr) {
    ptr->sendData("This some sample data");
    cout << ptr->getData() << endl;
}

int main() {
    auto eth0 = unique_ptr<INetworkInterface>{ make_unique<EthernetNetwork>() };
    auto eth1 = unique_ptr<INetworkInterface>{ make_unique<WifiNetwork>() };

    int n;
    cin >> n;

    if( n == 1 )
        sendMessage(eth0.get());
    else
        sendMessage(eth1.get());

    return 0;
}
