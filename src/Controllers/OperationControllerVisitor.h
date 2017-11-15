#ifndef CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_
#define CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_

#include "StartController.h"
#include "InitialGameDecitionController.h"
#include "ActionController.h"

namespace Controllers {

class OperationControllerVisitor {
public:
	virtual void visit(StartController &startController) = 0;
	virtual void visit(InitialGameDecitionController &initialGameDecitionController) = 0;
	virtual void visit(ActionController &actionController) = 0;
};

} /* namespace Controllers */

#endif /* CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_ */
