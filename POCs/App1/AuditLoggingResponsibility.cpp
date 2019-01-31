#include "AuditLoggingResponsibility.h"
#include <iostream>

bool AuditLoggingResponsibility::operator()(const DSPMessage& msg) {
	std::cout << "Going to perform logging";
	return true;
}