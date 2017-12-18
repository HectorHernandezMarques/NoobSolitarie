#ifndef CONTROLLERS_LOCAL_STARTCONTROLLER_H_
#define CONTROLLERS_LOCAL_STARTCONTROLLER_H_

#include "../StartController.h"
#include "OperationController.h"

namespace Controllers {
namespace Local {

class StartController: public virtual Controllers::StartController, public Controllers::Local::OperationController {
public:
	StartController(Models::Game &game);
	virtual ~StartController();

	void accept(OperationControllerVisitor &operationControllerVisitor);
	Controllers::Error execute();
};

} /* namespace Local */
} /* namespace Controller */

#endif /* CONTROLLERS_LOCAL_STARTCONTROLLER_H_ */
