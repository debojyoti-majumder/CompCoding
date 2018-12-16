#include "ApplicationController.h"
#include "EventSource.h"
#include "Poco/Observer.h"

std::shared_ptr<ApplicationController> ApplicationController::_instance = nullptr;
std::mutex ApplicationController::_instanceMutex;

ApplicationController::ApplicationController() {
	_eventSources.emplace_back(std::thread{ EventSource{_applicationNotificationCenter} });
	_eventSources.emplace_back(std::thread{ EventSource{_applicationNotificationCenter, 30, "USB"} });
	_eventSources.emplace_back(std::thread{ EventSource{_applicationNotificationCenter, 20, "GPIO"} });

	addObservers();
};

void ApplicationController::addObservers() {
	// Subscribing to the HW events
	_applicationNotificationCenter.addObserver(Poco::Observer<HwEventHandler, USBEventNotfication>
		(_evtHandler, &HwEventHandler::handleUSBEvent));
	_applicationNotificationCenter.addObserver(Poco::Observer<HwEventHandler, GPIOEventNotification>
		(_evtHandler, &HwEventHandler::handleGPIOEvent));
}

void ApplicationController::removeObservers() {
	_applicationNotificationCenter.removeObserver(Poco::Observer<HwEventHandler, USBEventNotfication>
		(_evtHandler, &HwEventHandler::handleUSBEvent));
	_applicationNotificationCenter.removeObserver(Poco::Observer<HwEventHandler, GPIOEventNotification>
		(_evtHandler, &HwEventHandler::handleGPIOEvent));
}

std::shared_ptr < ApplicationController > ApplicationController::getInstance() {
	std::lock_guard<std::mutex> lockGuard{ _instanceMutex };
	if (_instance == nullptr)
		_instance = std::shared_ptr<ApplicationController>(new ApplicationController());

	return _instance;
}

void ApplicationController::run() {
	// Waiting for all the threads to complete
	for (auto& t : _eventSources)
		t.join();
}

ApplicationController::~ApplicationController() {
	removeObservers();
	std::cout << "Exiting controller" << std::endl;
}
