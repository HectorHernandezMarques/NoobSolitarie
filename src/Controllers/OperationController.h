#ifndef CONTROLLERS_OPERATIONCONTROLLER_H_
#define CONTROLLERS_OPERATIONCONTROLLER_H_

#include "Controller.h"

namespace Controllers {

class OperationControllerVisitor;

class OperationController : public virtual Controller{
public:
	virtual void accept(OperationControllerVisitor &operationControllerVisitor) = 0;
};

}/* namespace Controllers */

#endif /* CONTROLLERS_OPERATIONCONTROLLER_H_ */
