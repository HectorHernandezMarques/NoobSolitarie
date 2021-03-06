#include "FlipController.h"

namespace Controllers {
namespace Local {

FlipController::FlipController(Models::Game &game) :
		Controllers::Local::ActionController(game) {
	assert(&game);
}

FlipController::FlipController(const FlipController &rhs) : FlipController(rhs.game){
	assert(&game);
}

FlipController::~FlipController() {
}

void FlipController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

bool FlipController::available() {
	return this->game.canFlip();
}

Controllers::Error FlipController::execute() {
	Controllers::Error result = Controllers::Error::CANT_FLIP;
	if (this->game.canFlip()) {
		this->game.flip();
		this->game.takeMemento();
		result = Controllers::Error::NO_ERROR;
	}
	this->setState(Models::State::IN_GAME);
	return result;
}

InitialGameDecition FlipController::getName() {
	return InitialGameDecition::FLIP;
}

Controllers::ActionController& FlipController::clone() {
	return *new FlipController(*this);
}

} /* namespace Local */
} /* namespace Controller */
