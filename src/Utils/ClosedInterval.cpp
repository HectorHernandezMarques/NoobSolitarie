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

int ClosedInterval::getMax(){
	return this->max;
}

int ClosedInterval::getMin(){
	return this->min;
}

} /* namespace Utils */
