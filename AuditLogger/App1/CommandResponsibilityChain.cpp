#include "CommandResponsibilityChain.h"

void CommandResponsibilityChain::addToDSPChain(std::function<bool(const DSPMessage&)> fn) {
}

void CommandResponsibilityChain::addToGPIOChain(std::function<bool(const GPIOMessage&)> fn) {
}

void CommandResponsibilityChain::executeCommand(const DSPMessage& message) const {
}

void CommandResponsibilityChain::executeCommand(const GPIOMessage& message) const {
}
