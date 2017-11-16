#ifndef VIEWS_CONSOLE_PUTCARDINTABLEAUVIEW_H_
#define VIEWS_CONSOLE_PUTCARDINTABLEAUVIEW_H_

#include "PutCardView.h"
#include "../../Controllers/PutCardInTableauController.h"

namespace Views {
namespace Console {

class PutCardInTableauView: public virtual PutCardView {
public:
	PutCardInTableauView();
	virtual ~PutCardInTableauView();

	void interact(Controllers::PutCardController &putCardInTableauController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_PUTCARDINTABLEAUVIEW_H_ */
