#include "DeskmirroringResponsibility.h"
#include <iostream>

bool DeskmirroringResponsibility::operator()(const DSPMessage& msg) {
	std::cout << "Preforming desk mirroring" << std::endl;
	return true;
}