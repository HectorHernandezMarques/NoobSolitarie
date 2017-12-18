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
	putCardInTableauController.setTargetChoice(choosenTargetTableauIndex);
}

} /* namespace Console */
} /* namespace Views */
