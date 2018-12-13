#pragma once

#include "EventNotifications.h"

class HwEventHandler {
public:
	void handleUSBEvent(USBEventNotfication* eventData);
	void handleGPIOEvent(GPIOEventNotification* eventData);
};