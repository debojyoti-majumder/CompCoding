#pragma once
#include <string>

struct DSPMessage {
	short channelNumber;
	std::string dspFunction;
	float parameeterValue;
};

struct GPIOMessage{
	short channelNumber;
	bool isOn;
};

class MessageInterpreter {
private:
	std::string _message;

public:
	explicit MessageInterpreter(const std::string& m);
	DSPMessage getDSPMessage() const;
	GPIOMessage getGpioMessage() const;
};