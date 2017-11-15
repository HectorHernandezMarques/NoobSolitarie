#ifndef UTILS_CLOSEDINTERVAL_H_
#define UTILS_CLOSEDINTERVAL_H_

#include <cassert>

namespace Utils {

class ClosedInterval {
private:
	int min;
	int max;

public:
	ClosedInterval(int min, int max);
	virtual ~ClosedInterval();
	bool includes(int value);

	int getMax();
	int getMin();
};

} /* namespace Utils */

#endif /* UTILS_CLOSEDINTERVAL_H_ */
