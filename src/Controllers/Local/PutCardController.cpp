#include "PutCardController.h"

namespace Controllers {
namespace Local {

PutCardController::PutCardController(Models::Game &game, Controllers::CardChoice& cardChoice) :
		Controllers::Local::Controller(game), cardChoice(cardChoice), targetStackAddable(nullptr) {
	assert(&game);
	assert(&cardChoice);
}

PutCardController::~PutCardController() {
}

Error PutCardController::setTargetChoice(int targetTableauIndex) {
	Error error = Error::CANT_PUT_CARD;
	this->targetStackAddable = &(this->getStackAddable(targetTableauIndex));
	if (this->cardChoice.canAddInStack(*(this->targetStackAddable))) {
		error = Error::NO_ERROR;
	}
	return error;
}

void PutCardController::putCard() {
	assert(this->targetStackAddable);

	this->targetStackAddable->add(this->cardChoice.getCards());
	this->cardChoice.removeCard();
}

} /* namespace Local */
} /* namespace Controllers */
