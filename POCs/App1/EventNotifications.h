#pragma once

#include <string>
#include "Poco/NotificationCenter.h"

class USBEventNotfication : public Poco::Notification {
public:
	std::string rawMessage;
	explicit USBEventNotfication(const std::string& msg) : rawMessage(msg) {}
};

class UnknownEventNotification : public Poco::Notification {
public:
	int errorCode;
	explicit UnknownEventNotification() : errorCode(5) {}
};

class GPIOEventNotification : public Poco::Notification {
public:
	int portNumber;
	bool isOn;

	GPIOEventNotification() : portNumber(-1), isOn(false) {}
};