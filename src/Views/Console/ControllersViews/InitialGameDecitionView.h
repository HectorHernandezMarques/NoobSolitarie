#ifndef VIEWS_CONSOLE_CONTROLLERS_INITIALGAMEDECITIONVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_INITIALGAMEDECITIONVIEW_H_

#include "../../../Controllers/InitialGameDecitionController.h"
#include "../../../Controllers/InitialGameDecition.h"
#include "../ModelsViews/BoardView.h"
#include "../ModelsViews/LimitedIntDialogView.h"
#include "../ModelsViews/InitialGameDecitionNameView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class InitialGameDecitionView{
public:
	InitialGameDecitionView();
	virtual ~InitialGameDecitionView();

	void interact(Controllers::InitialGameDecitionController &initialGameDecitionController);
};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_INITIALGAMEDECITIONVIEW_H_ */
