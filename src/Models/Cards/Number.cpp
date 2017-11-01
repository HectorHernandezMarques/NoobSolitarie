#include "Number.h"

namespace Models{
namespace Cards {

Number::Number(int number, int maxNumber) {
	assert(number >= 0);
	assert(maxNumber >= 0);

	this->number = number;
	this->maxNumber = maxNumber;
}

Number::~Number() {
}

bool Number::isFirst() {
	return this->number == 0;
}

bool Number::isLast() {
	return this->number == this->maxNumber - 1;
}

bool Number::isNextOf(Number &cardNumber) {
	assert(&cardNumber);

	return this->number == (cardNumber.number + 1);
}

bool Number::operator==(Number &cardNumber) {
	assert(&cardNumber);

	return this->number == cardNumber.number;
}

int Number::getNumber() {
	return this->number;
}

} /* namespace Cards */
} /* namespace Models */
