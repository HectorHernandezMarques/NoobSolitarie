#include "FlipController.h"

namespace Controllers {
namespace Local {

FlipController::FlipController(Models::Game &game) :
		Controllers::Local::ActionController(game) {
	assert(&game);
}

FlipController::~FlipController() {
}

void FlipController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

Controllers::Error FlipController::flip() {
	Controllers::Error result = Controllers::Error::NO_ERROR;
	if (this->game.canFlip()) {
		this->game.flip();
	} else {
		result = Controllers::Error::CANT_FLIP;
	}
	this->setState(Models::State::IN_GAME);
	return result;
}

} /* namespace Local */
} /* namespace Controller */
