// This seems to be a buggy impl, have to fix it later
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class DeviceCommand {
    private:
        string _targetIP;
        string _commandString;

    public:
        DeviceCommand() = delete;
        DeviceCommand(const string& str, string name) : _targetIP(str) , _commandString(name) {
        };
        virtual ~DeviceCommand() = default;

        string getDeviceHandle() {
            return _targetIP + "->" + _commandString;
        }

        inline string getTarget() const { return _commandString; }
};

class SimpleExcuteAction {
    private:
        SimpleExcuteAction* next;

    protected:
        DeviceCommand& _command;

    public:
        SimpleExcuteAction() = delete;
        SimpleExcuteAction(DeviceCommand& comm) : _command(comm) , next(nullptr) {
        }

        virtual void handle() {
            if( next ) next->handle();
            cout << "Executing command on " << _command.getDeviceHandle() << endl;
        }

        void addResponsibility(SimpleExcuteAction* action) {
            if( next )
                next->addResponsibility(action);
            else
                next = action;
        }
};

class AuditLogging : public SimpleExcuteAction {
    public:
        AuditLogging() = delete;
        AuditLogging(DeviceCommand c) : SimpleExcuteAction(c) {

        }

        void handle() override {
            auto now = chrono::system_clock::now();
            std::time_t t = chrono::system_clock::to_time_t(now);
            std::cout << std::ctime(&t) << " ";

            SimpleExcuteAction::handle();
        }
};

class CommandPermission : public SimpleExcuteAction {
    public:
        CommandPermission() = delete;
        CommandPermission(DeviceCommand& c) : SimpleExcuteAction(c) {

        }

        void handle() override {
            if( _command.getTarget() == "localhost" ) {
                cout << "Not allowed";
            }

            SimpleExcuteAction::handle();
        }
};

int main() {
    DeviceCommand c1("localhost", "login");
    DeviceCommand c2("10.23.33.27", "login");

    auto action1 = new SimpleExcuteAction(c1);
    auto action2 = new SimpleExcuteAction(c2);

    action1->addResponsibility(new AuditLogging(c1));
    action1->addResponsibility(new CommandPermission(c1));

    action2->addResponsibility(new AuditLogging(c2));
    action2->addResponsibility(new CommandPermission(c2));

    action1->handle();
    action2->handle();
    return 0;
}
