/*
 * Number.h
 *
 *  Created on: Oct 22, 2017
 *      Author: eherhes
 */

#ifndef NUMBER_H_
#define NUMBER_H_

#include <string>

namespace Cards {

class Number {
private:
protected:
	int number;
	int maxNumber;
public:
	Number();
	Number(int number, int maxNumber);
	virtual ~Number();

	bool isLastNumber() {
		return this->number == this->maxNumber - 1;
	}
	bool isNextNumberOf(Number *cardNumber) {
		return this->number == (cardNumber->number + 1);
	}
	virtual std::string toString() = 0;

	bool operator==(const Number &cardNumber) {
		return this->number == cardNumber.number;
	}

	int getNumber() {
		return this->number;
	}
};

} /* namespace Cards */

#endif /* NUMBER_H_ */
