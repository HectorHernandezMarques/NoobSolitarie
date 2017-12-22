#ifndef VIEWS_CONSOLE_CONTROLLERS_STARTVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_STARTVIEW_H_

#include "../../../Controllers/StartController.h"
#include "../ModelsViews/BoardView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class StartView{
public:
	StartView();
	virtual ~StartView();

	void interact(Controllers::StartController &startController);
};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_STARTVIEW_H_ */
