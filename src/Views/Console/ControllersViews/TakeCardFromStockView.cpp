#include "./TakeCardFromStockView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

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

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */
