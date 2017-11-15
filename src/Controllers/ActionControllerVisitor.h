#ifndef CONTROLLERS_ACTIONCONTROLLERVISITOR_H_
#define CONTROLLERS_ACTIONCONTROLLERVISITOR_H_

#include "FlipController.h"
#include "MoveController.h"

namespace Controllers {

class ActionControllerVisitor {
public:
	virtual void visit(FlipController &flipController) = 0;
	virtual void visit(MoveController &moveController) = 0;
};

} /* namespace Controllers */

#endif /* CONTROLLERS_ACTIONCONTROLLERVISITOR_H_ */
