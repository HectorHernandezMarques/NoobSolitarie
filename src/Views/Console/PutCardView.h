#ifndef VIEWS_CONSOLE_PUTCARDVIEW_H_
#define VIEWS_CONSOLE_PUTCARDVIEW_H_

#include "../../Controllers/PutCardController.h"
#include "LimitedIntDialogView.h"

namespace Views {
namespace Console {

class PutCardView {
public:
	virtual void interact(Controllers::PutCardController &putCardController) = 0;
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_PUTCARDVIEW_H_ */
