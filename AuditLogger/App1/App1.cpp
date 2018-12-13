// App1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <thread>

#include "Poco/NotificationCenter.h"
#include "Poco/Observer.h"

#include "EventSource.h"
#include "EventNotifications.h"
#include "HwEventHandler.h"

int main() {
	Poco::NotificationCenter mainNotificationCenter;
	HwEventHandler evtHandler;

	// Event source are platform dependent
	EventSource s1(mainNotificationCenter);
	EventSource s2(mainNotificationCenter, 20, "USB");
	EventSource s3(mainNotificationCenter, 30, "GPIO");

	thread t1(s1);
	thread t2(s2);
	thread t3(s3);

	// Subscribing to the HW events
	mainNotificationCenter.addObserver(Poco::Observer<HwEventHandler, USBEventNotfication>
		(evtHandler, &HwEventHandler::handleUSBEvent));
	mainNotificationCenter.addObserver(Poco::Observer<HwEventHandler, GPIOEventNotification>
		(evtHandler, &HwEventHandler::handleGPIOEvent));

	t1.join();
	t2.join();
	t3.join();
}
