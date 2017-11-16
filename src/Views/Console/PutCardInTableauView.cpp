#include "PutCardInTableauView.h"

namespace Views {
namespace Console {

PutCardInTableauView::PutCardInTableauView() {
}

PutCardInTableauView::~PutCardInTableauView() {
}

void PutCardInTableauView::interact(Controllers::PutCardController &putCardInTableauController) {
	LimitedIntDialogView targetTableauLimitedIntDialogView(
			*(new Utils::LimitedIntDialog("Enter the Tableau where you want to insert your card(s)", 1,
					putCardInTableauController.getTableausNumberMax())));
	targetTableauLimitedIntDialogView.write();
	int choosenTargetTableauIndex = targetTableauLimitedIntDialogView.read() - 1;
	Controllers::Error error = putCardInTableauController.setTargetChoice(choosenTargetTableauIndex);
	if (error == Controllers::Error::NO_ERROR) {
		putCardInTableauController.putCard();
	}
}

} /* namespace Console */
} /* namespace Views */
