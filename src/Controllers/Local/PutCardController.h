#ifndef CONTROLLERS_LOCAL_PUTCARDCONTROLLER_H_
#define CONTROLLERS_LOCAL_PUTCARDCONTROLLER_H_

#include "../PutCardController.h"
#include "Controller.h"

namespace Controllers {
namespace Local {

class PutCardController: public virtual Controllers::PutCardController, public Controllers::Local::Controller {
private:
	Controllers::CardChoice& cardChoice;
	Models::StackAddable *targetStackAddable;

	virtual Models::StackAddable& getStackAddable(int targetStackIndex) = 0;

public:
	PutCardController(Models::Game &game, Controllers::CardChoice& cardChoice);
	virtual ~PutCardController();

	Error setTargetChoice(int targetStackIndex);
	void putCard();
};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_PUTCARDCONTROLLER_H_ */
