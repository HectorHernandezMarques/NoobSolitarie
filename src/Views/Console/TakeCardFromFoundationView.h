#ifndef VIEWS_CONSOLE_TAKECARDFROMFOUNDATIONVIEW_H_
#define VIEWS_CONSOLE_TAKECARDFROMFOUNDATIONVIEW_H_

#include "TakeCardView.h"
#include "../../Controllers/TakeCardFromFoundationController.h"

namespace Views {
namespace Console {

class TakeCardFromFoundationView {
public:
	TakeCardFromFoundationView();
	virtual ~TakeCardFromFoundationView();

	Controllers::CardChoice& interact(Controllers::TakeCardFromFoundationController &takeCardFromFoundationController);
	Controllers::Error checkChoice(int foundationIndex);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_TAKECARDFROMFOUNDATIONVIEW_H_ */
