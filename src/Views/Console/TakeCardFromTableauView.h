#ifndef VIEWS_CONSOLE_TAKECARDFROMTABLEAUVIEW_H_
#define VIEWS_CONSOLE_TAKECARDFROMTABLEAUVIEW_H_

#include "TakeCardView.h"
#include "../../Controllers/TakeCardFromTableauController.h"

namespace Views {
namespace Console {

class TakeCardFromTableauView {
public:
	TakeCardFromTableauView();
	virtual ~TakeCardFromTableauView();

	Controllers::CardChoice& interact(Controllers::TakeCardFromTableauController &takeCardFromTableauController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_TAKECARDFROMTABLEAUVIEW_H_ */
