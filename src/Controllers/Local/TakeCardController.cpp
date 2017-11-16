#include "TakeCardController.h"

namespace Controllers {
namespace Local {

TakeCardController::TakeCardController(Models::Game &game) :
		Controllers::Local::Controller(game), cardChoice(nullptr) {
	assert(&game);

}

TakeCardController::~TakeCardController() {

}

CardChoice& TakeCardController::getCardChoice() {
	assert(this->cardChoice);

	return *this->cardChoice;
}

} /* namespace Local */
} /* namespace Controllers */
