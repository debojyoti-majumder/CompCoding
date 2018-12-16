#pragma once

#include "MessageInterpreter.h"

class CommandDispatchingResponsibility {
public:
	bool operator()(const DSPMessage&);
};