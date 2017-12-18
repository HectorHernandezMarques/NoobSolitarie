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

Controllers::Error PutCardController::execute() {
	assert(this->targetStackAddable);

	Error error = Error::CANT_PUT_CARD;
	if (this->cardChoice.canAddInStack(*(this->targetStackAddable))) {
		this->targetStackAddable->add(this->cardChoice.getCards());
		error = Error::NO_ERROR;
	}
	return error;
}

void PutCardController::setTargetChoice(int targetTableauIndex) {
	this->targetStackAddable = &(this->getStackAddable(targetTableauIndex));
}

} /* namespace Local */
} /* namespace Controllers */
