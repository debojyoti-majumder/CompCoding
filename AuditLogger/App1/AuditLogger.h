#pragma once

#include <memory>
#include <mutex>
#include <thread>

class AuditLogger {
private:
	AuditLogger() = default;

	static std::shared_ptr<AuditLogger> _instance;
	static std::mutex					_instanceMutex;

public:
	static std::shared_ptr<AuditLogger> getInstance();
};