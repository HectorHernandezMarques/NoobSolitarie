#ifndef VIEWS_CONSOLE_TAKECARDVIEW_H_
#define VIEWS_CONSOLE_TAKECARDVIEW_H_

#include "../../Controllers/TakeCardController.h"
#include "LimitedIntDialogView.h"

namespace Views {
namespace Console {

class TakeCardView {
public:
	virtual Controllers::CardChoice& interact(Controllers::TakeCardController &takeCardController) = 0;
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_TAKECARDVIEW_H_ */
