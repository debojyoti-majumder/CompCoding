#include "EventSource.h"
#include "EventNotifications.h"

#include <thread>
#include <sstream>
#include "Poco/Random.h"

EventSource::EventSource(Poco::NotificationCenter& nc) : _loopCount{ 10 },
	_eventSource{ "Unknown" },
	_notificationCenter(nc) {}

EventSource::EventSource(Poco::NotificationCenter& nc, size_t t, const std::string& src) : _loopCount{ t },
	_eventSource{ src },
	_notificationCenter(nc) {}

// Main event loop
void EventSource::operator()() {
	for (size_t i = 0; i < _loopCount; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		postEvent(buildStringMessage());
	}
}

std::string EventSource::buildStringMessage() {
	std::stringstream message;
	Poco::Random randomGenerator;
	
	message << _eventSource << " ";
	if (randomGenerator.nextBool()) {
		message << "DSPFn1" << " ";
	}
	else {
		message << "DSPFn2" << " ";
	}

	message << randomGenerator.nextFloat() << " ";
	return message.str();
}

void EventSource::postEvent(const std::string & msg) {
	if (_eventSource == "USB")
		_notificationCenter.postNotification(new USBEventNotfication(msg));
	else if (_eventSource == "GPIO")
		_notificationCenter.postNotification(new GPIOEventNotification());
	else
		_notificationCenter.postNotification(new UnknownEventNotification());
}