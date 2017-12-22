#ifndef CONTROLLERS_LOCAL_UNDOCONTROLLER_H_
#define CONTROLLERS_LOCAL_UNDOCONTROLLER_H_

#include "../UndoController.h"
#include "./ActionController.h"

namespace Controllers {
namespace Local {

class UndoController : public virtual Controllers::UndoController, public Controllers::Local::ActionController {
public:
	UndoController(Models::Game &game);
	UndoController(const UndoController &rhs);
	virtual ~UndoController();

	void accept(ActionControllerVisitor &actionControllerVisitor);
	bool available();
	Controllers::Error execute();

	InitialGameDecition getName();
	Controllers::ActionController& clone();
};

} /* namespace Local */
} /* namespace Controller */

#endif /* CONTROLLERS_LOCAL_UNDOCONTROLLER_H_ */
