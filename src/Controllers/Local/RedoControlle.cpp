#include "./RedoController.h"

namespace Controllers {
namespace Local {

RedoController::RedoController(Models::Game &game) :
	Controllers::Local::ActionController(game) {
	assert(&game);
}

RedoController::~RedoController() {
}

void RedoController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

Controllers::Error RedoController::execute() {
	Controllers::Error result = Controllers::Error::CANT_REDO;
	if (this->game.canRedo()) {
		this->game.redo();
		result = Controllers::Error::NO_ERROR;
	}
	this->setState(Models::State::IN_GAME);
	return result;
}

} /* namespace Local */
} /* namespace Controller */
