#ifndef CONTROLLERS_LOCAL_INITIALGAMEDECITIONCONTROLLER_H_
#define CONTROLLERS_LOCAL_INITIALGAMEDECITIONCONTROLLER_H_

#include "../InitialGameDecition.h"
#include "OperationController.h"

namespace Controllers {
namespace Local {

class InitialGameDecitionController: public virtual Controllers::InitialGameDecitionController, public Controllers::Local::OperationController {
public:
	InitialGameDecitionController(Models::Game &game);
	virtual ~InitialGameDecitionController();

	void accept(OperationControllerVisitor &operationControllerVisitor);
	void makeDecition(InitialGameDecition initialGameDecition);
};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_INITIALGAMEDECITIONCONTROLLER_H_ */
