#include "pch.h"
#include "HwEventHandler.h"
#include <iostream>

void HwEventHandler::handleUSBEvent(USBEventNotfication* eventData) {
	std::cout << eventData->name() << std::endl;
	std::cout << eventData->rawMessage;

	// Clean up 
	eventData->release();
}

void HwEventHandler::handleGPIOEvent(GPIOEventNotification* eventData) {
	std::cout << "Got GPIO data" << std::endl;
	eventData->release();
}