#ifndef VIEWS_CONSOLE_CONTROLLERS_TAKECARDFROMFOUNDATIONVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_TAKECARDFROMFOUNDATIONVIEW_H_

#include "./TakeCardView.h"
#include "../../../Controllers/TakeCardFromFoundationController.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class TakeCardFromFoundationView {
public:
	TakeCardFromFoundationView();
	virtual ~TakeCardFromFoundationView();

	Controllers::CardChoice& interact(Controllers::TakeCardFromFoundationController &takeCardFromFoundationController);
};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_TAKECARDFROMFOUNDATIONVIEW_H_ */
