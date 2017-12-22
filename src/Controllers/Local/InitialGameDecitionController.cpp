#include "InitialGameDecitionController.h"

namespace Controllers {
namespace Local {

InitialGameDecitionController::InitialGameDecitionController(Models::Game &game,  std::list<Controllers::ActionController*> availableCommandsNames) :
		Controllers::Local::OperationController(game), availableCommandsNames(availableCommandsNames){
	assert(&game);
}

InitialGameDecitionController::~InitialGameDecitionController() {
}

void InitialGameDecitionController::accept(OperationControllerVisitor &operationControllerVisitor) {
	assert(&operationControllerVisitor);

	operationControllerVisitor.visit(*this);
}

Controllers::Error InitialGameDecitionController::execute() {
	assert(&this->initialGameDecition);

	Controllers::Error result = Controllers::Error::NO_ERROR;
	switch (this->initialGameDecition) {
	case InitialGameDecition::FLIP:
		this->setState(Models::State::FLIPPING_CARDS);
		break;
	case InitialGameDecition::MOVE:
		this->setState(Models::State::MOVING_CARDS);
		break;
	case InitialGameDecition::REDO:
		this->setState(Models::State::REDOING);
		break;
	case InitialGameDecition::UNDO:
		this->setState(Models::State::UNDOING);
		break;
	default:
		result = Controllers::Error::COMMAND_NOT_AVAILABLE;
	}
	return result;
}

void InitialGameDecitionController::setInitialGameDecition(InitialGameDecition initialGameDecition) {
	this->initialGameDecition = initialGameDecition;
}

std::list<InitialGameDecition> InitialGameDecitionController::getAvailableCommandsNames() {
	std::list<InitialGameDecition> result;
	for(auto it = this->availableCommandsNames.begin(); it != this->availableCommandsNames.end(); ++it) {
		if((*it)->available()) {
			result.push_back((*it)->getName());
		}
	}

	return result;
}

} /* namespace Local */
} /* namespace Controllers */
