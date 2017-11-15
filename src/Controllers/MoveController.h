#ifndef CONTROLLERS_MOVECONTROLLER_H_
#define CONTROLLERS_MOVECONTROLLER_H_

#include "ActionController.h"

namespace Controllers {

class MoveController : public virtual ActionController{
public:
	virtual Error canTakeCardFromFoundation(int foundationIndex) = 0;
	virtual Error canTakeCardFromTableau(int tableauIndex, int relativeCardIndex) = 0;
	virtual Error canTakeCardFromStock() = 0;
	virtual Error canPutCard(Models::StackAddable &stackAddable, Utils::Stack<Models::Cards::Card> &cards) = 0;
	virtual Error selectCardsToTake() = 0;
	virtual Error selectCardsToPut() = 0;

	virtual int getVisibleCardsNumberFromTableau(int index) = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_MOVECONTROLLER_H_ */
