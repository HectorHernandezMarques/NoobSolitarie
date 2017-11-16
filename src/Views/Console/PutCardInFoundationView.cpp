#include "PutCardInFoundationView.h"

namespace Views {
namespace Console {

PutCardInFoundationView::PutCardInFoundationView() {
}

PutCardInFoundationView::~PutCardInFoundationView() {
}

void PutCardInFoundationView::interact(Controllers::PutCardController &putCardInFoundationController) {
	assert(&putCardInFoundationController);

	LimitedIntDialogView targetFoundationLimitedIntDialogView(
			*(new Utils::LimitedIntDialog("Enter the Foundation where you want to insert your card(s)", 1,
					putCardInFoundationController.getSuitNumberMax())));
	targetFoundationLimitedIntDialogView.write();
	int choosenTargetTableauIndex = targetFoundationLimitedIntDialogView.read() - 1;
	Controllers::Error error = putCardInFoundationController.setTargetChoice(choosenTargetTableauIndex);
	if (error == Controllers::Error::NO_ERROR) {
		putCardInFoundationController.putCard();
	}
}

} /* namespace Console */
} /* namespace Views */
