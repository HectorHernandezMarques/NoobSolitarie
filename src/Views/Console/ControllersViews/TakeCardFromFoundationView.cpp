#include "./TakeCardFromFoundationView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

TakeCardFromFoundationView::TakeCardFromFoundationView() {
}

TakeCardFromFoundationView::~TakeCardFromFoundationView() {
}

Controllers::CardChoice& TakeCardFromFoundationView::interact(
		Controllers::TakeCardFromFoundationController &takeCardFromFoundationController) {
	assert(&takeCardFromFoundationController);

	Controllers::CardChoice *result = nullptr;
	ModelsViews::LimitedIntDialogView limitedIntDialogView(
			*(new Utils::LimitedIntDialog("Enter the Foundation you want to access", 1,
					takeCardFromFoundationController.getSuitNumberMax())));
	limitedIntDialogView.write();
	int choosenSouceFoundationIndex = limitedIntDialogView.read() - 1;
	Controllers::Error error = takeCardFromFoundationController.setChoice(choosenSouceFoundationIndex);
	if (error == Controllers::Error::NO_ERROR) {
		result = new Controllers::CardChoice(takeCardFromFoundationController.getCardChoice());
	}
	return *result;
}

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */
