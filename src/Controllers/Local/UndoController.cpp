#include "./UndoController.h"

namespace Controllers {
namespace Local {

UndoController::UndoController(Models::Game &game) :
	Controllers::Local::ActionController(game) {
	assert(&game);
}

UndoController::~UndoController() {
}

void UndoController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

Controllers::Error UndoController::execute() {
	Controllers::Error result = Controllers::Error::CANT_UNDO;
	if (this->game.canUndo()) {
		this->game.undo();
		result = Controllers::Error::NO_ERROR;
	}
	this->setState(Models::State::IN_GAME);
	return result;
}

} /* namespace Local */
} /* namespace Controller */