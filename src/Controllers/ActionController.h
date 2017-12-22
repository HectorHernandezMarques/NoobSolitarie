#ifndef CONTROLLERS_ACTIONCONTROLLER_H_
#define CONTROLLERS_ACTIONCONTROLLER_H_

#include "OperationController.h"
#include "InitialGameDecition.h"

namespace Controllers {

class ActionControllerVisitor;

class ActionController : public virtual OperationController{
public:
	virtual void accept(ActionControllerVisitor &actionControllerVisitor) = 0;
	virtual bool available() = 0;

	virtual InitialGameDecition getName() = 0;
	virtual ActionController& clone() = 0;
};

} /* namespace Controllers */

#endif /* CONTROLLERS_ACTIONCONTROLLER_H_ */
