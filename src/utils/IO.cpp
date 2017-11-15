#include "IO.h"

namespace Utils {

IO *IO::io = new IO();

IO::IO() {

}

IO::~IO() {

}

int IO::readInt(std::string title) {
	assert(&title);

	this->writeln(title);
	int input;
	while (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Se esperaba un entero";
	}
	return input;
}

std::string IO::readString(std::string title) {
	assert(&title);

	this->writeln(title);
	std::string input;
	while (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Se esperaba un string";
	}
	return input;
}

void IO::write(std::string text) {
	assert(&text);

	std::cout << text;
}

void IO::writeln(std::string text) {
	assert(&text);

	std::cout << text << "\n";
}

IO& IO::getInstance() {
	return *IO::io;
}

} /* namespace Utils */
