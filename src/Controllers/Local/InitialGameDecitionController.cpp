#include "InitialGameDecitionController.h"

namespace Controllers {
namespace Local {

InitialGameDecitionController::InitialGameDecitionController(Models::Game &game) :
		Controllers::Local::OperationController(game) {
	assert(&game);
}

InitialGameDecitionController::~InitialGameDecitionController() {
}

void InitialGameDecitionController::accept(OperationControllerVisitor &operationControllerVisitor) {
	assert(&operationControllerVisitor);

	operationControllerVisitor.visit(*this);
}

void InitialGameDecitionController::makeDecition(InitialGameDecition initialGameDecition) {
	switch (initialGameDecition) {
	case InitialGameDecition::FLIP_CARDS:
		this->setState(Models::State::FLIPPING_CARDS);
		break;
	case InitialGameDecition::MOVE_CARDS:
		this->setState(Models::State::MOVING_CARDS);
		break;
	default:
		assert(false);
	}
}

} /* namespace Local */
} /* namespace Controllers */
