#include "./Logic.h"

namespace Controllers {
namespace Local {

Logic::Logic() : game(), actionControllerBuilder(this->game){
}

Logic::~Logic() {
}

Controllers::Local::OperationController& Logic::getOperationController() {
	Controllers::Local::OperationController *result;
	switch (this->game.getState()) {
	case Models::State::INITIAL:
		result = new Controllers::Local::StartController(this->game);
		break;
	case Models::State::IN_GAME:
		result = new Controllers::Local::InitialGameDecitionController(this->game, this->actionControllerBuilder.getAvailableCommands());
		break;
	case Models::State::FLIPPING_CARDS:
		result = new Controllers::Local::FlipController(this->game);
		break;
	case Models::State::MOVING_CARDS:
		result = new Controllers::Local::MoveController(this->game);
		break;
	case Models::State::UNDOING:
		result = new Controllers::Local::UndoController(this->game);
		break;
	case Models::State::REDOING:
		result = new Controllers::Local::RedoController(this->game);
		break;
	case Models::State::FINAL:
		//result = new Controllers::ContinueController(this->game)
		break;
	case Models::State::EXIT:
		result = nullptr;
		break;
	}

	return *result;
}

} /* namespace Local */
} /* namespace Models */
