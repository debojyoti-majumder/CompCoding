#pragma once

#include "EventNotifications.h"
#include "CommandResponsibilityChain.h"

class HwEventHandler {
private:
	CommandResponsibilityChain _respChain;

public:
	HwEventHandler();
	void handleUSBEvent(USBEventNotfication* eventData);
	void handleGPIOEvent(GPIOEventNotification* eventData);
};