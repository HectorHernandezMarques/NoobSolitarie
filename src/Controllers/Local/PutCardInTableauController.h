#ifndef CONTROLLERS_LOCAL_PUTCARDINTABLEAUCONTROLLER_H_
#define CONTROLLERS_LOCAL_PUTCARDINTABLEAUCONTROLLER_H_

#include "../PutCardController.h"
#include "PutCardController.h"

namespace Controllers {
namespace Local {

class PutCardInTableauController: public Controllers::Local::PutCardController {
public:
	Models::StackAddable& getStackAddable(int targetTableauIndex);

public:
	PutCardInTableauController(Models::Game &game, Controllers::CardChoice& cardChoice);
	virtual ~PutCardInTableauController();

};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_PUTCARDINTABLEAUCONTROLLER_H_ */
