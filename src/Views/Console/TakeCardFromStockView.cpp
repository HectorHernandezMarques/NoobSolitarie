#include "TakeCardFromStockView.h"

namespace Views {
namespace Console {

TakeCardFromStockView::TakeCardFromStockView() {
}

TakeCardFromStockView::~TakeCardFromStockView() {
}

Controllers::CardChoice& TakeCardFromStockView::interact(Controllers::TakeCardFromStockController &takeCardFromStockController) {
	assert(&takeCardFromStockController);

	Controllers::CardChoice *result = nullptr;
	Controllers::Error error = takeCardFromStockController.setChoice();
	if (error == Controllers::Error::NO_ERROR) {
		result = new Controllers::CardChoice(takeCardFromStockController.getCardChoice());
	}
	return *result;
}

} /* namespace Console */
} /* namespace Views */
