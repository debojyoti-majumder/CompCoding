// App1.cpp : Dummy Logger application

#include "ApplicationController.h"

int main() {
	auto appController = ApplicationController::getInstance();
	appController->run();

	return 0;
}
