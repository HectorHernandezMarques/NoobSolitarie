/*
 * Number.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: eherhes
 */

#include "Number.h"

namespace Cards {

Number::Number() {
	this->number = 0;
	this->maxNumber = 0;
}

Number::Number(int number, int maxNumber) {
	this->number = number;
	this->maxNumber = maxNumber;
}

Number::~Number() {
}

} /* namespace Cards */
