#include "TakeCardFromTableauController.h"

namespace Controllers {
namespace Local {

TakeCardFromTableauController::TakeCardFromTableauController(Models::Game &game) :
		Controllers::Local::TakeCardController(game) {
}

TakeCardFromTableauController::~TakeCardFromTableauController() {
}

Controllers::Error TakeCardFromTableauController::setChoice(int sourceTableauIndex, int relativeSourceCardIndex){
	assert(0 <= sourceTableauIndex && sourceTableauIndex < this->getTableausNumberMax());

	Controllers::Error result = Controllers::Error::CANT_TAKE_CARD;
	Models::Tableau &sourceTableau = this->getTableau(sourceTableauIndex);
	if (sourceTableau.canRemoveRelativeCards(relativeSourceCardIndex)) {
		result = Controllers::Error::NO_ERROR;
		this->cardChoice = new CardChoice(&sourceTableau, sourceTableau.getRelativeCards(relativeSourceCardIndex));
	}
	return result;
}

int TakeCardFromTableauController::getVisibleCardsNumberFromTableau(int index){
	assert(0 <= index && index < this->getTableausNumberMax());

	return this->game.getVisibleCardsNumberFromTableau(index);
}

} /* namespace Controllers */
} /* namespace Local */
