#include "./RedoController.h"

namespace Controllers {
namespace Local {

RedoController::RedoController(Models::Game &game) :
	Controllers::Local::ActionController(game) {
	assert(&game);
}

RedoController::RedoController(const RedoController &rhs) : RedoController(rhs.game){
	assert(&game);
}

RedoController::~RedoController() {
}

void RedoController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

bool RedoController::available() {
	return this->game.canRedo();
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

InitialGameDecition RedoController::getName() {
	return InitialGameDecition::REDO;
}

Controllers::ActionController& RedoController::clone() {
	return *new RedoController(*this);
}

} /* namespace Local */
} /* namespace Controller */
