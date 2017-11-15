#include "MoveController.h"

namespace Controllers {
namespace Local {

MoveController::MoveController(Models::Game &game) :
		Controllers::Local::ActionController(game) {
	assert(&game);
}

MoveController::~MoveController() {
}

void MoveController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

Controllers::Error MoveController::canTakeCardFromFoundation(int foundationIndex) {
	Controllers::Error result = Controllers::Error::CANT_TAKE_CARD;
	if (this->getFoundation(foundationIndex).canRemoveRelativeCards()) {
		result = Controllers::Error::NO_ERROR;
	}
	return result;
}

Controllers::Error MoveController::canTakeCardFromTableau(int tableauIndex, int relativeCardIndex) {
	Controllers::Error result = Controllers::Error::CANT_TAKE_CARD;
	if (this->getTableau(tableauIndex).canRemoveRelativeCards(relativeCardIndex)) {
		result = Controllers::Error::NO_ERROR;
	}
	return result;
}

Controllers::Error MoveController::canTakeCardFromStock() {
	Controllers::Error result = Controllers::Error::CANT_TAKE_CARD;
	if (this->getStock().canRemoveRelativeCards()) {
		result = Controllers::Error::NO_ERROR;
	}
	return result;
}

Controllers::Error MoveController::canPutCard(Models::StackAddable &stackAddable, Utils::Stack<Models::Cards::Card> &cards) {
	Controllers::Error result = Controllers::Error::CANT_PUT_CARD;
	if (stackAddable.canAdd(cards)) {
		result = Controllers::Error::NO_ERROR;
	}
	return result;
}

Controllers::Error MoveController::selectCardsToTake() {
	return Controllers::Error::NO_ERROR;
}

Controllers::Error MoveController::selectCardsToPut() {
	return Controllers::Error::NO_ERROR;
}

int MoveController::getVisibleCardsNumberFromTableau(int index) {
	return this->game.getVisibleCardsNumberFromTableau(index);
}

} /* namespace Local */
} /* namespace Controller */
