#include "PutCardInTableauController.h"

namespace Controllers {
namespace Local {

PutCardInTableauController::PutCardInTableauController(Models::Game &game, Controllers::CardChoice& cardChoice) :
		Controllers::Local::PutCardController(game, cardChoice) {
	assert(&game);
	assert(&cardChoice);
}

PutCardInTableauController::~PutCardInTableauController() {
}

Models::StackAddable& PutCardInTableauController::getStackAddable(int targetTableauIndex) {
	assert(0 <= targetTableauIndex && targetTableauIndex < this->getTableausNumberMax());

	return this->game.getTableau(targetTableauIndex);
}

} /* namespace Controllers */
} /* namespace Local */
