#pragma once

#pragma once

#include <functional>
#include <vector>
#include "MessageInterpreter.h"

class CommandResponsibilityChain {
private:
	std::vector<std::function<bool(const DSPMessage&)>>		_dspChain;
	std::vector<std::function<bool(const GPIOMessage&)>>	_gpioChain;
public:
	void addToDSPChain(std::function<bool(const DSPMessage&)>);
	void addToGPIOChain(std::function<bool(const GPIOMessage&)>);

	void executeCommand(const DSPMessage&) const;
	void executeCommand(const GPIOMessage&) const;
};