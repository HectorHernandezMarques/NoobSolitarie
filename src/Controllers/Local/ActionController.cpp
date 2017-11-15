#include "ActionController.h"

namespace Controllers {
namespace Local {

ActionController::ActionController(Models::Game &game) :
		Controllers::Local::OperationController(game) {
	assert(&game);
}

ActionController::~ActionController() {
}

void ActionController::accept(OperationControllerVisitor &operationControllerVisitor) {
	assert(&operationControllerVisitor);

	operationControllerVisitor.visit(*this);
}

} /* namespace Local */
} /* namespace Controllers */
