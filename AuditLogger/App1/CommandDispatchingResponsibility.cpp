#include "CommandDispatchingResponsibility.h"
#include <iostream>

bool CommandDispatchingResponsibility::operator()(const DSPMessage& msg) {
	std::cout << "Should be sending out DSP command to DSP" << std::endl;
	return true;
}