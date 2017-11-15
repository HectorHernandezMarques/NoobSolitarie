#ifndef CONTROLLERS_LOCAL_MOVECONTROLLER_H_
#define CONTROLLERS_LOCAL_MOVECONTROLLER_H_

#include "../MoveController.h"
#include "ActionController.h"

namespace Controllers {
namespace Local {

class MoveController: public virtual Controllers::MoveController, public Controllers::Local::ActionController {
public:
	MoveController(Models::Game &game);
	virtual ~MoveController();

	void accept(ActionControllerVisitor &actionControllerVisitor);

	Controllers::Error canTakeCardFromFoundation(int foundationIndex);
	Controllers::Error canTakeCardFromTableau(int tableauIndex, int relativeCardIndex);
	Controllers::Error canTakeCardFromStock();
	Controllers::Error canPutCard(Models::StackAddable &stackAddable, Utils::Stack<Models::Cards::Card> &cards);
	Controllers::Error selectCardsToTake();
	Controllers::Error selectCardsToPut();

	int getVisibleCardsNumberFromTableau(int index);
};

} /* namespace Local */
} /* namespace Controller */

#endif /* CONTROLLERS_LOCAL_MOVECONTROLLER_H_ */
