#pragma once

#include "MessageInterpreter.h"

class DeskmirroringResponsibility {
public:
	bool operator()(const DSPMessage&);
};