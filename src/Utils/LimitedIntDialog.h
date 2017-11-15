#ifndef UTILS_LIMITEDINTDIALOG_H_
#define UTILS_LIMITEDINTDIALOG_H_

#include "IO.h"
#include "ClosedInterval.h"

namespace Utils {

class LimitedIntDialog {
private:
	std::string title;
	ClosedInterval closedInterval;

public:
	LimitedIntDialog(std::string title, int min, int max);
	LimitedIntDialog(std::string title, int max);
	virtual ~LimitedIntDialog();

	std::string getTitle();
	ClosedInterval &getClosedInterval();
	int getMin();
	int getMax();

};

} /* namespace Utils */

#endif /* UTILS_LIMITEDINTDIALOG_H_ */
