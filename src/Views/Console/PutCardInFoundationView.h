#ifndef VIEWS_CONSOLE_PUTCARDINFOUNDATIONVIEW_H_
#define VIEWS_CONSOLE_PUTCARDINFOUNDATIONVIEW_H_

#include "PutCardView.h"
#include "../../Controllers/PutCardInFoundationController.h"

namespace Views {
namespace Console {

class PutCardInFoundationView : public virtual PutCardView{
public:
	PutCardInFoundationView();
	virtual ~PutCardInFoundationView();

	void interact(Controllers::PutCardController &putCardInFoundationController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_PUTCARDINFOUNDATIONVIEW_H_ */
