// For this command situation where this chain needs craeting multiple times for the same 
// way but with different commands might be use full to use prototype pattern

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class DeviceCommand {
	private:
		string _targetIp;
		string _command;
	public:
		DeviceCommand() = delete;
		
		// TODO: Parse these parameters
		DeviceCommand(string ip, string command) {
			_command = command;
			_targetIp = ip;
		}

		void execute() {
			cout << " Executing at " << _targetIp << " " << _command << endl;
		}

		inline string getIp() const { return _targetIp; }
		inline string getCommand() const { return _command; }
};

class NoActionResponsibility {
	private:
		NoActionResponsibility* next;

	protected:
		DeviceCommand & _command;

	public:
		NoActionResponsibility() = delete;
		NoActionResponsibility(DeviceCommand& command) : _command(command) {
			next = nullptr;
		}
	
		virtual void handle() {
			if (next)	
				next->handle();
			else
				_command.execute();
		}

		void addResponsibility(NoActionResponsibility* action) {
			if (next)
				next->addResponsibility(action);
			else
				next = action;
		}

		virtual ~NoActionResponsibility() {

		}
};

class LoggingAction : public NoActionResponsibility {
	public:
		LoggingAction() = delete;
		
		LoggingAction(DeviceCommand& comm) : NoActionResponsibility(comm) {

		}

		void handle() override {
			cout << "Command executed at this time:";
			
			// This function enables the flow of command to continue
			NoActionResponsibility::handle();
		}
};

class SecurityAction : public NoActionResponsibility {
	public:	
		SecurityAction() = delete;

		SecurityAction(DeviceCommand& comm) : NoActionResponsibility(comm) {
		}

		void handle() override {
			// Not calling the base method breaks the chain
			if (_command.getCommand() == "logout") {
				cout << "Access denied" << endl;
			}
			else {
				// The chain continues
				cout << "Permission Grated" << endl;
				NoActionResponsibility::handle();
			}
		}
};

int main() {
	string inpCmd;
	cin >> inpCmd;

	DeviceCommand c1{ "localhost", inpCmd };
	NoActionResponsibility r1(c1);
	LoggingAction r2(c1);
	SecurityAction r3(c1);

	r1.addResponsibility(&r3);			// The security starts first
	r1.addResponsibility(&r2);			// The the auditing

	// The chain starts from the top
	r1.handle();
	
	return 0;
}
