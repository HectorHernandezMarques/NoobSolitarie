/*
 * ClosedInterval.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: eherhes
 */

#include "ClosedInterval.h"

namespace Utils {

ClosedInterval::ClosedInterval(int min, int max) {
	assert(min <= max);

	this->min = min;
	this->max = max;
}

ClosedInterval::~ClosedInterval() {
}

bool ClosedInterval::includes(int value) {
	return min <= value && value <= max;
}

} /* namespace Utils */
