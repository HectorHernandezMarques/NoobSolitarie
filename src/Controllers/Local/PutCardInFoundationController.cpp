#include "PutCardInFoundationController.h"

namespace Controllers {
namespace Local {

PutCardInFoundationController::PutCardInFoundationController(Models::Game &game, Controllers::CardChoice& cardChoice) :
		Controllers::Local::PutCardController(game, cardChoice){
	assert(&game);
	assert(&cardChoice);
}

PutCardInFoundationController::~PutCardInFoundationController() {
}

Models::StackAddable& PutCardInFoundationController::getStackAddable(int targetFoundationIndex) {
	assert(0 <= targetFoundationIndex && targetFoundationIndex < this->getSuitNumberMax());

	return this->game.getFoundation(targetFoundationIndex);
}

} /* namespace Controllers */
} /* namespace Local */
