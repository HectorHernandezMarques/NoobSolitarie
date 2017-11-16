#include "TakeCardFromStockController.h"

namespace Controllers {
namespace Local {

TakeCardFromStockController::TakeCardFromStockController(Models::Game &game) :
		Controllers::Local::TakeCardController(game) {
}

TakeCardFromStockController::~TakeCardFromStockController() {
}

Error TakeCardFromStockController::checkChoice() {
	Controllers::Error result = Controllers::Error::CANT_TAKE_CARD;
	Models::Stock &sourceStock = this->getStock();
	if (sourceStock.canRemoveRelativeCards()) {
		result = Controllers::Error::NO_ERROR;
		this->cardChoice = new CardChoice(&sourceStock, sourceStock.getRelativeCards());
	}
	return result;
}

} /* namespace Local */
} /* namespace Controllers */
