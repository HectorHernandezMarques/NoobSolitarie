#include "./MoveView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

MoveView::MoveView() {
}

MoveView::~MoveView() {
}

void MoveView::interact(Controllers::MoveController &moveController) {
	assert(&moveController);

	Controllers::CardChoice *cardChoice;
	ModelsViews::LimitedIntDialogView sourceAreaLimitedIntDialogView(
			*(new Utils::LimitedIntDialog(
					"Enter the section you want to access [1=Foundations(top), 2=Tableaus(middle), 3=Stock(bottom)]", 1, 3)));
	sourceAreaLimitedIntDialogView.write();
	int choosenSourceArea = sourceAreaLimitedIntDialogView.read();
	switch (choosenSourceArea) {
	case 1:
		cardChoice = &(new TakeCardFromFoundationView())->interact(moveController.getTakeCardFromFoundationController());
		break;
	case 2:
		cardChoice = &(new TakeCardFromTableauView())->interact(moveController.getTakeCardFromTableauController());
		break;
	case 3:
		cardChoice = &(new TakeCardFromStockView())->interact(moveController.getTakeCardFromStockController());
		break;
	}

	if (cardChoice) {
		(new ModelsViews::BoardView(moveController.getBoard()))->write();
		(new ModelsViews::CardChoiceView(*cardChoice))->write();

		ModelsViews::LimitedIntDialogView targetAreaLimitedIntDialogView(
				*(new Utils::LimitedIntDialog(
						"Enter the section you want to insert your card(s) [1=Foundations(top), 2=Tableau(middle)]", 1, 2)));
		targetAreaLimitedIntDialogView.write();
		int choosenTargetArea = targetAreaLimitedIntDialogView.read();
		switch (choosenTargetArea) {
		case 1:
			(new PutCardInFoundationView())->interact(moveController.getPutCardInFoundationController(*cardChoice));
			break;
		case 2:
			(new PutCardInTableauView())->interact(moveController.getPutCardInTableauController(*cardChoice));
			break;
		}
		moveController.execute();
	}
	moveController.setState(Models::State::IN_GAME);
}

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */
