#pragma once

#include "EventNotifications.h"

class HwEventHandler {
private:

public:
	void handleUSBEvent(USBEventNotfication* eventData);
	void handleGPIOEvent(GPIOEventNotification* eventData);
};