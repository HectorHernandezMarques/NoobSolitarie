#ifndef VIEWS_CONSOLE_CLOSEDINTERVALVIEW_H_
#define VIEWS_CONSOLE_CLOSEDINTERVALVIEW_H_

#include "../../ModelView.h"
#include "../../../Utils/ClosedInterval.h"
#include "../../../Utils/IO.h"

namespace Views {
namespace Console {
namespace ModelsViews {

class ClosedIntervalView {
private:
	Utils::ClosedInterval &closedInterval;

public:
	ClosedIntervalView(Utils::ClosedInterval &closedInterval);
	virtual ~ClosedIntervalView();

	void write();
};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CLOSEDINTERVALVIEW_H_ */
