#include "Poco/Crypto/Crypto.h"
#include "Poco/SHA1Engine.h"
#include <iostream>
#include <string>

int main() {
	std::string input;
	Poco::SHA1Engine engine;

	std::cin >> input;
	engine.update(input);
	auto shaDigest = engine.digest();

	for( const auto& ref: shaDigest )
		std::cout << (int) ref << "";
	
	std::cout << std::endl;
	return 0;
}
