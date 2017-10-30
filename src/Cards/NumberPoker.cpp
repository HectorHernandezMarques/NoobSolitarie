/*
 * NumberPoker.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: eherhes
 */

#include "NumberPoker.h"

namespace Cards {

NumberPoker::~NumberPoker() {
}

std::string NumberPoker::toString() {
	switch (this->number) {
	case 0:
		return "A";

	case 10:
		return "J";

	case 11:
		return "Q";

	case 12:
		return "K";

	default:
		return std::to_string(this->number + 1);
	}
}

} /* namespace Cards */
