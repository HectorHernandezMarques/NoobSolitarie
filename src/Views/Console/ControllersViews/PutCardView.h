#ifndef VIEWS_CONSOLE_CONTROLLERS_PUTCARDVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_PUTCARDVIEW_H_

#include "../../../Controllers/PutCardController.h"
#include "../ModelsViews/LimitedIntDialogView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class PutCardView {
public:
	virtual void interact(Controllers::PutCardController &putCardController) = 0;
};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_PUTCARDVIEW_H_ */
