#pragma once

#include "MessageInterpreter.h"

MessageInterpreter::MessageInterpreter(const std::string& m) : _message(m) {
}

DSPMessage MessageInterpreter::getDSPMessage() const {
	DSPMessage m;

	return m;
}

GPIOMessage MessageInterpreter::getGpioMessage() const {
	return GPIOMessage{};
}