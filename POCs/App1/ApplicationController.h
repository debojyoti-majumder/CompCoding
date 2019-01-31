#pragma once

#include <memory>
#include <mutex>
#include <vector>
#include <thread>

#include "Poco/NotificationCenter.h"
#include "HwEventHandler.h"

class ApplicationController {
private:
	static std::shared_ptr<ApplicationController> _instance;
	static std::mutex _instanceMutex;

	std::vector<std::thread>	_eventSources;
	Poco::NotificationCenter	_applicationNotificationCenter;
	HwEventHandler				_evtHandler;

	ApplicationController();
	void addObservers();
	void removeObservers();

public:
	static std::shared_ptr < ApplicationController > getInstance();
	void run();
	~ApplicationController();
};
