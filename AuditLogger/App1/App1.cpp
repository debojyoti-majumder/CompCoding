// App1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <thread>
#include <chrono>

#include "Poco/NotificationCenter.h"
#include "EventSource.h"

int main() {
	Poco::NotificationCenter mainNotificationCenter;
	
	EventSource s1(mainNotificationCenter);
	EventSource s2(mainNotificationCenter, 20, "USB");

	thread t1(s1);
	thread t2(s2);

	t1.join();
	t2.join();
}
