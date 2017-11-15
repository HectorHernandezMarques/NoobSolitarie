#ifndef CONTROLLERS_LOCAL_ACTIONCONTROLLER_H_
#define CONTROLLERS_LOCAL_ACTIONCONTROLLER_H_

#include "../ActionController.h"
#include "OperationController.h"
#include "../ActionControllerVisitor.h"

namespace Controllers {
namespace Local {

class ActionController: public virtual Controllers::ActionController, public Controllers::Local::OperationController{
public:
	ActionController(Models::Game &game);
	virtual ~ActionController();

	void accept(OperationControllerVisitor &operationControllerVisitor);
	virtual void accept(ActionControllerVisitor &actionControllerVisitor) = 0;

};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_ACTIONCONTROLLER_H_ */
