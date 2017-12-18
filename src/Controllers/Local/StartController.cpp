#include "StartController.h"

namespace Controllers {
namespace Local {

StartController::StartController(Models::Game &game) :
		Controllers::Local::OperationController(game) {
	assert(&game);
}

StartController::~StartController() {
}

void StartController::accept(OperationControllerVisitor &operationControllerVisitor) {
	assert(&operationControllerVisitor);

	operationControllerVisitor.visit(*this);
}

Controllers::Error StartController::execute() {
	this->setState(Models::State::IN_GAME);
	this->game.takeMemento();
	return Controllers::Error::NO_ERROR;
}

} /* namespace Local */
} /* namespace Controller */
