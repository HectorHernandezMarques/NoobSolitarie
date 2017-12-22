#include "./TakeCardFromTableauView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

TakeCardFromTableauView::TakeCardFromTableauView() {
}

TakeCardFromTableauView::~TakeCardFromTableauView() {
}

Controllers::CardChoice& TakeCardFromTableauView::interact(
		Controllers::TakeCardFromTableauController &takeCardFromTableauController) {
	assert(&takeCardFromTableauController);

	Controllers::CardChoice *result = nullptr;

	ModelsViews::LimitedIntDialogView sourceTableauLimitedIntDialogView(
			*(new Utils::LimitedIntDialog("Enter the Tableau you want to access", 1,
					takeCardFromTableauController.getTableausNumberMax())));
	sourceTableauLimitedIntDialogView.write();
	int choosenSourceTableauIndex = sourceTableauLimitedIntDialogView.read() - 1;
	if(takeCardFromTableauController.getVisibleCardsNumberFromTableau(choosenSourceTableauIndex)){
		ModelsViews::LimitedIntDialogView sourceCardLimitedIntDialogView(
				*(new Utils::LimitedIntDialog("Enter the card you want to access", 1,
						takeCardFromTableauController.getVisibleCardsNumberFromTableau(choosenSourceTableauIndex))));
		sourceCardLimitedIntDialogView.write();
		int choosenSourceCardIndex = sourceCardLimitedIntDialogView.read();

		Controllers::Error error = takeCardFromTableauController.setChoice(choosenSourceTableauIndex, choosenSourceCardIndex);
		if (error == Controllers::Error::NO_ERROR) {
			result = new Controllers::CardChoice(takeCardFromTableauController.getCardChoice());
		}
	}
	return *result;
}

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */
