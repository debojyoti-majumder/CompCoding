#include "CommandResponsibilityChain.h"
#include <iostream>

void CommandResponsibilityChain::addToDSPChain(std::function<bool(const DSPMessage&)> fn) {
	_dspChain.emplace_back(fn);
}

void CommandResponsibilityChain::addToGPIOChain(std::function<bool(const GPIOMessage&)> fn) {
	_gpioChain.emplace_back(fn);
}

void CommandResponsibilityChain::executeCommand(const DSPMessage& message) const {
	for (auto& func : _dspChain) {
		auto ret = func(message);
		
		// false would be returned if encounter with any problem
		if( ret == false ) {
			std::cout << "Command chain failure" << std::endl;
			return;
		}
	}
}

void CommandResponsibilityChain::executeCommand(const GPIOMessage& message) const {
	// Do not care about the retrun value
	for (auto& fn : _gpioChain) {
		fn(message);
	}
}
