#ifndef VIEWS_CONSOLE_CONTROLLERS_TAKECARDVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_TAKECARDVIEW_H_

#include "../../../Controllers/TakeCardController.h"
#include "../ModelsViews/LimitedIntDialogView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class TakeCardView {
public:
	virtual Controllers::CardChoice& interact(Controllers::TakeCardController &takeCardController) = 0;
};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_TAKECARDVIEW_H_ */
