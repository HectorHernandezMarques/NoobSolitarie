#ifndef CONTROLLERS_LOCAL_PUTCARDINFOUNDATIONCONTROLLER_H_
#define CONTROLLERS_LOCAL_PUTCARDINFOUNDATIONCONTROLLER_H_

#include "PutCardController.h"

namespace Controllers {
namespace Local {

class PutCardInFoundationController: public Controllers::Local::PutCardController {
private:
	Models::StackAddable& getStackAddable(int targetFoundationIndex);

public:
	PutCardInFoundationController(Models::Game &game, Controllers::CardChoice& cardChoice);
	virtual ~PutCardInFoundationController();

};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_PUTCARDINFOUNDATIONCONTROLLER_H_ */
