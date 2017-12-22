#ifndef CONTROLLERS_LOCAL_ACTIONCONTROLLERBUILDER_H_
#define CONTROLLERS_LOCAL_ACTIONCONTROLLERBUILDER_H_

#include "./FlipController.h"
#include "./MoveController.h"
#include "./UndoController.h"
#include "./RedoController.h"

namespace Controllers {
namespace Local {

class ActionControllerBuilder {
private:
	std::list<Controllers::ActionController*> actionControllers;

public:
	ActionControllerBuilder(Models::Game &game);
	virtual ~ActionControllerBuilder();

	std::list<Controllers::ActionController*> getAvailableCommands();
};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_ACTIONCONTROLLERBUILDER_H_ */
