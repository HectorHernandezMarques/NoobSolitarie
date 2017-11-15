#include "MoveView.h"

namespace Views {
namespace Console {

MoveView::MoveView() {
}

MoveView::~MoveView() {
}

void MoveView::interact(Controllers::MoveController &moveController) {
	assert(&moveController);

	LimitedIntDialogView* limitedIntDialogView;
	int choosenBoardArea;
	int choosenStackIndex;
	int choosenCardIndex;
	Controllers::Error error;
	Models::Stack *choosenStack;
	Utils::Stack<Models::Cards::Card> *choosenCard;

	limitedIntDialogView = new LimitedIntDialogView(
			*(new Utils::LimitedIntDialog(
					"Enter the section you want to access [1=Foundations(top), 2=Tableaus(middle), 3=Stock(bottom)]", 1, 3)));
	limitedIntDialogView->write();
	choosenBoardArea = limitedIntDialogView->read();
	switch (choosenBoardArea) {
	case 1:
		limitedIntDialogView = new LimitedIntDialogView(
				*(new Utils::LimitedIntDialog("Enter the Foundation you want to access", 1, moveController.getSuitNumberMax())));
		limitedIntDialogView->write();
		choosenStackIndex = limitedIntDialogView->read() - 1;
		error = moveController.canTakeCardFromFoundation(choosenStackIndex);
		if (error == Controllers::Error::NO_ERROR) {
			choosenStack = &moveController.getFoundation(choosenStackIndex);
			choosenCard = &((Models::Foundation *) choosenStack)->getRelativeCards();
		}
		break;
	case 2:
		limitedIntDialogView = new LimitedIntDialogView(
				*(new Utils::LimitedIntDialog("Enter the Tableau you want to access", 1, moveController.getTableausNumberMax())));
		limitedIntDialogView->write();
		choosenStackIndex = limitedIntDialogView->read() - 1;

		limitedIntDialogView = new LimitedIntDialogView(
				*(new Utils::LimitedIntDialog("Enter the card you want to access", 1,
						moveController.getVisibleCardsNumberFromTableau(choosenStackIndex))));
		limitedIntDialogView->write();
		choosenCardIndex = limitedIntDialogView->read();
		error = moveController.canTakeCardFromTableau(choosenStackIndex, choosenCardIndex);
		if (error == Controllers::Error::NO_ERROR) {
			choosenStack = &(moveController.getTableau(choosenStackIndex));
			choosenCard = &((Models::Tableau *) choosenStack)->getRelativeCards(choosenCardIndex);
		}
		break;
	case 3:
		error = moveController.canTakeCardFromStock();
		if (error == Controllers::Error::NO_ERROR) {
			choosenStack = &moveController.getStock();
			choosenCard = &((Models::Stock *) choosenStack)->getRelativeCards();
		}
		break;
	}




	int choosenTargetStackIndex;
	Models::StackAddable *choosenTargetStack;
	limitedIntDialogView = new LimitedIntDialogView(
			*(new Utils::LimitedIntDialog(
					"Enter the section you want to insert your card(s) [1=Foundations(top), 2=Tableau(middle)]", 1, 2)));
	limitedIntDialogView->write();
	choosenBoardArea = limitedIntDialogView->read();
	switch (choosenBoardArea) {
	case 1:
		limitedIntDialogView = new LimitedIntDialogView(
				*(new Utils::LimitedIntDialog("Enter the Foundation where you want to insert your card(s)", 1,
						moveController.getSuitNumberMax())));
		limitedIntDialogView->write();
		choosenTargetStackIndex = limitedIntDialogView->read() - 1;
		choosenTargetStack = &moveController.getFoundation(choosenTargetStackIndex);
		error = moveController.canPutCard(*choosenTargetStack, *choosenCard);
		if (error == Controllers::Error::NO_ERROR) {
			choosenTargetStack->add(choosenStack->remove(choosenCard->get(0)));
		}
		break;
	case 2:
		limitedIntDialogView = new LimitedIntDialogView(
				*(new Utils::LimitedIntDialog("Enter the Tableau where you want to insert your card(s)", 1,
						moveController.getTableausNumberMax())));
		limitedIntDialogView->write();
		choosenTargetStackIndex = limitedIntDialogView->read() - 1;
		choosenTargetStack = &moveController.getTableau(choosenTargetStackIndex);
		error = moveController.canPutCard(*choosenTargetStack, *choosenCard);
		if (error == Controllers::Error::NO_ERROR) {
			choosenTargetStack->add(choosenStack->remove(choosenCard->get(0)));
		}
		break;
	}
	moveController.setState(Models::State::IN_GAME);
}

} /* namespace Console */
} /* namespace Views */
