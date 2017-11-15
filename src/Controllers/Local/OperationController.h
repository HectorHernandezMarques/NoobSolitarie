#ifndef CONTROLLERS_LOCAL_OPERATIONCONTROLLER_H_
#define CONTROLLERS_LOCAL_OPERATIONCONTROLLER_H_

#include "../OperationController.h"
#include "Controller.h"
#include "../OperationControllerVisitor.h"

namespace Controllers {
namespace Local {

class OperationController: public virtual Controllers::OperationController, public Controllers::Local::Controller {
public:
	OperationController(Models::Game &game);
	virtual ~OperationController();

	virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_OPERATIONCONTROLLER_H_ */
