#pragma once

#include <string>
#include "Poco/NotificationCenter.h"

class EventSource {
private:
	size_t						_loopCount;
	std::string					_eventSource;
	Poco::NotificationCenter&	_notificationCenter;
	
	std::string buildStringMessage();
	void postEvent(const std::string& msg);

public:
	explicit EventSource(Poco::NotificationCenter& nc);
	EventSource(Poco::NotificationCenter& nc, size_t t, const std::string& src);

	void operator()();
};