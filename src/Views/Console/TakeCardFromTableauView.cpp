#include "TakeCardFromTableauView.h"

namespace Views {
namespace Console {

TakeCardFromTableauView::TakeCardFromTableauView() {
}

TakeCardFromTableauView::~TakeCardFromTableauView() {
}

Controllers::CardChoice& TakeCardFromTableauView::interact(
		Controllers::TakeCardFromTableauController &takeCardFromTableauController) {
	assert(&takeCardFromTableauController);

	Controllers::CardChoice *result = nullptr;

	LimitedIntDialogView sourceTableauLimitedIntDialogView(
			*(new Utils::LimitedIntDialog("Enter the Tableau you want to access", 1,
					takeCardFromTableauController.getTableausNumberMax())));
	sourceTableauLimitedIntDialogView.write();
	int choosenSourceTableauIndex = sourceTableauLimitedIntDialogView.read() - 1;
	if(takeCardFromTableauController.getVisibleCardsNumberFromTableau(choosenSourceTableauIndex)){
		LimitedIntDialogView sourceCardLimitedIntDialogView(
				*(new Utils::LimitedIntDialog("Enter the card you want to access", 1,
						takeCardFromTableauController.getVisibleCardsNumberFromTableau(choosenSourceTableauIndex))));
		sourceCardLimitedIntDialogView.write();
		int choosenSourceCardIndex = sourceCardLimitedIntDialogView.read();

		Controllers::Error error = takeCardFromTableauController.checkChoice(choosenSourceTableauIndex, choosenSourceCardIndex);
		if (error == Controllers::Error::NO_ERROR) {
			result = new Controllers::CardChoice(takeCardFromTableauController.getCardChoice());
		}
	}
	return *result;
}

} /* namespace Console */
} /* namespace Views */
