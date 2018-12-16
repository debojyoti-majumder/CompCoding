#include "HwEventHandler.h"
#include "MessageInterpreter.h"
#include <iostream>

class CommandDispatchingResponsibility {
public:
	bool operator()(const DSPMessage& msg) {
		std::cout << "Should be sending out DSP command to DSP" << std::endl;
		return true;
	}
};

class AuditLoggingResponsibility {
public:
	bool operator()(const DSPMessage& msg) {
		std::cout << "Should do DB logging" << std::endl;
		return true;
	}
};

class DeskmirroringResponsibility {
public:
	bool operator()(const DSPMessage& msg) {
		std::cout << "Should send data out to the other mixing console" << std::endl;
		return true;
	}
};

bool exampleFunction(const DSPMessage& msg) {
	return true;
}

HwEventHandler::HwEventHandler() {
	CommandDispatchingResponsibility resp1;
	AuditLoggingResponsibility resp2;
	DeskmirroringResponsibility resp3;

	_respChain.addToDSPChain(std::move(resp1));
	_respChain.addToDSPChain(std::move(resp2));
	_respChain.addToDSPChain(std::move(resp3));
}

void HwEventHandler::handleUSBEvent(USBEventNotfication* eventData) {
	MessageInterpreter mInter(eventData->rawMessage);

	try {
		auto dspData = mInter.getDSPMessage();
		_respChain.executeCommand(dspData);
	}	
	catch (...) {
		std::cout << "Error in parsing message\n";
	}

	// Clean up 
	eventData->release();
}

void HwEventHandler::handleGPIOEvent(GPIOEventNotification* eventData) {
	GPIOMessage m;
	m.channelNumber = eventData->portNumber;
	m.isOn = eventData->isOn;

	_respChain.executeCommand(m);
	eventData->release();
}