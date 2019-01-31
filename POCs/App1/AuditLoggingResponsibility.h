#pragma once
#include "MessageInterpreter.h"

class AuditLoggingResponsibility {
public:
	bool operator()(const DSPMessage&);
};