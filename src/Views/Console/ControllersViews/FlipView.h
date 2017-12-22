#ifndef VIEWS_CONSOLE_CONTROLLERS_FLIPVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_FLIPVIEW_H_

#include "../../../Controllers/FlipController.h"
#include "../../../Utils/IO.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class FlipView {
public:
	FlipView();
	virtual ~FlipView();

	void interact(Controllers::FlipController &flipController);

};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_FLIPVIEW_H_ */
