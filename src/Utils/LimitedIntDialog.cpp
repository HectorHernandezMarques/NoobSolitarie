#include "LimitedIntDialog.h"

namespace Utils {

LimitedIntDialog::LimitedIntDialog(std::string title, int min, int max) : title(title), closedInterval(min, max){
	assert(&title);
	assert(min <= max);
}

LimitedIntDialog::LimitedIntDialog(std::string title, int max) : LimitedIntDialog(title, 0, max) {
	assert(&title);
	assert(0 <= max);
}

LimitedIntDialog::~LimitedIntDialog() {
}

std::string LimitedIntDialog::getTitle() {
	return this->title;
}

ClosedInterval& LimitedIntDialog::getClosedInterval() {
	return this->closedInterval;
}

int LimitedIntDialog::getMin() {
	return this->closedInterval.getMin();
}

int LimitedIntDialog::getMax() {
	return this->closedInterval.getMax();
}

} /* namespace Utils */
