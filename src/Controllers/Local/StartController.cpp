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

void StartController::start() {
	this->setState(Models::State::IN_GAME);
}

} /* namespace Local */
} /* namespace Controller */
