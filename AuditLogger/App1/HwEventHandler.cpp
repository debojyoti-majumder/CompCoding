#include "HwEventHandler.h"
#include "MessageInterpreter.h"
#include <iostream>

void HwEventHandler::handleUSBEvent(USBEventNotfication* eventData) {
	MessageInterpreter mInter(eventData->rawMessage);

	std::cout << eventData->name() << std::endl;
	std::cout << eventData->rawMessage;

	try {
		auto dspData = mInter.getDSPMessage();
	}
	catch (...) {
		std::cout << "Error in parsing message\n"
	}
	// Clean up 
	eventData->release();
}

void HwEventHandler::handleGPIOEvent(GPIOEventNotification* eventData) {
	std::cout << "Got GPIO data" << std::endl;
	eventData->release();
}