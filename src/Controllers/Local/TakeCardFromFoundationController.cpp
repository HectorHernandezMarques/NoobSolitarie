#include "TakeCardFromFoundationController.h"

namespace Controllers {
namespace Local {

TakeCardFromFoundationController::TakeCardFromFoundationController(Models::Game &game) :
		Controllers::Local::TakeCardController(game) {

}

TakeCardFromFoundationController::~TakeCardFromFoundationController() {
}

Error TakeCardFromFoundationController::checkChoice(int sourceFoundationIndex) {
	assert(0 <= sourceFoundationIndex && sourceFoundationIndex < this->getSuitNumberMax());

	Controllers::Error result = Controllers::Error::CANT_TAKE_CARD;
	Models::Foundation &sourceFoundation = this->getFoundation(sourceFoundationIndex);
	if (sourceFoundation.canRemoveRelativeCards()) {
		result = Controllers::Error::NO_ERROR;
		this->cardChoice = new CardChoice(&sourceFoundation, sourceFoundation.getRelativeCards());
	}
	return result;
}

} /* namespace Controllers */
} /* namespace Local */
