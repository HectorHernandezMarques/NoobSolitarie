#ifndef VIEWS_CONSOLE_CONTROLLERS_PUTCARDINTABLEAUVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_PUTCARDINTABLEAUVIEW_H_

#include "./PutCardView.h"
#include "../../../Controllers/PutCardController.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class PutCardInTableauView: public virtual PutCardView {
public:
	PutCardInTableauView();
	virtual ~PutCardInTableauView();

	void interact(Controllers::PutCardController &putCardInTableauController);
};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_PUTCARDINTABLEAUVIEW_H_ */
