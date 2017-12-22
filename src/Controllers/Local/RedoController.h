#ifndef CONTROLLERS_LOCAL_REDOCONTROLLER_H_
#define CONTROLLERS_LOCAL_REDOCONTROLLER_H_

#include "../RedoController.h"
#include "./ActionController.h"

namespace Controllers {
namespace Local {

class RedoController : public virtual Controllers::RedoController, public Controllers::Local::ActionController {
public:
	RedoController(Models::Game &game);
	RedoController(const RedoController &rhs);
	virtual ~RedoController();

	void accept(ActionControllerVisitor &actionControllerVisitor);
	bool available();
	Controllers::Error execute();

	InitialGameDecition getName();
	Controllers::ActionController& clone();
};

} /* namespace Local */
} /* namespace Controller */

#endif /* CONTROLLERS_LOCAL_REDOCONTROLLER_H_ */
