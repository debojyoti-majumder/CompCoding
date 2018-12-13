#pragma once

#include <string>
#include "Poco/NotificationCenter.h"

using namespace std;

class EventSource {
private:
	size_t						_loopCount;
	string						_eventSource;
	Poco::NotificationCenter&	_notificationCenter;
	
	string buildStringMessage();
	void postEvent(const string& msg);

public:
	explicit EventSource(Poco::NotificationCenter& nc);
	EventSource(Poco::NotificationCenter& nc, size_t t, const string& src);

	void operator()();
};