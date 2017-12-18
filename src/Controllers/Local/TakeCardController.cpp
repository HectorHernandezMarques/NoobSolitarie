#include "TakeCardController.h"

namespace Controllers {
namespace Local {

TakeCardController::TakeCardController(Models::Game &game) :
		Controllers::Local::Controller(game), cardChoice(nullptr) {
	assert(&game);

}

TakeCardController::~TakeCardController() {

}

Controllers::Error TakeCardController::execute() {
	assert(this->cardChoice);

	this->cardChoice->removeCard();
	return Controllers::Error::NO_ERROR;
}

CardChoice& TakeCardController::getCardChoice() {
	assert(this->cardChoice);

	return *this->cardChoice;
}

} /* namespace Local */
} /* namespace Controllers */
