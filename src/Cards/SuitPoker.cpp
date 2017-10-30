/*
 * SuitPoker.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: eherhes
 */

#include "SuitPoker.h"

namespace Cards {

SuitPoker::~SuitPoker() {
}

std::string SuitPoker::toString() {
	std::string result = "";
	switch (this->suit) {
	case 0:
		return result + (char) 3;

	case 1:
		return result + (char) 5;

	case 2:
		return result + (char) 4;

	case 3:
		return result + (char) 6;

	default:
		return "" + (char) (3 + this->suit);

	}
}

} /* namespace Cards */
