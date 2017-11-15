#ifndef CONTROLLERS_LOGIC_H_
#define CONTROLLERS_LOGIC_H_

#include "OperationController.h"
#include "../Models/Game.h"

namespace Controllers {

class Logic {
protected:
	Models::Game game;

public:
	Logic();
	virtual ~Logic();

	virtual OperationController& getOperationController() = 0;

};

} /* namespace Controllers */

#endif /* CONTROLLERS_LOGIC_H_ */
