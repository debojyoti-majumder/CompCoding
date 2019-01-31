#include "AuditLogger.h"

std::shared_ptr<AuditLogger> AuditLogger::_instance = nullptr;
std::mutex AuditLogger::_instanceMutex;

std::shared_ptr<AuditLogger> AuditLogger::getInstance() {
	std::lock_guard<std::mutex> gaurd{ _instanceMutex };

	if (_instance == nullptr)
		_instance = std::shared_ptr<AuditLogger>(new AuditLogger);

	return _instance;
}
