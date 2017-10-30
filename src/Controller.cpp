/*
 * Controller.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: eherhes
 */

#include "Controller.h"

Controller::Controller(Board *board) {
	this->board = board;
}

Controller::~Controller() {

}

void Controller::printBoard() {
	system("CLS");
	this->IO.writeln(this->board->toString());
}

void Controller::flipCard() {
	if (this->board->getStock()->canFlip()) {
		this->board->getStock()->flip();
	} else {
		this->IO.writeln("Can flip the stock");
	}
}

void Controller::moveCard() {
	Cards::Card *sourceCard;
	Stack *sourceStack;
	if (this->selectStackToTake(sourceStack, sourceCard)) {
		StackAddable *targetStack;
		if (this->selectStackToPut(targetStack, sourceCard)) {
			targetStack->add(sourceStack->remove(sourceCard));
		}
	}
}

bool Controller::selectStackToTake(Stack *&sourceStack, Cards::Card *&sourceCard) {
	int choosenBoardArea;
	int choosenStack;
	int choosenCard;
	bool result = false;
	do {
		choosenBoardArea = this->IO.readInt(
				"Enter the section you want to access [1=Foundations(top), 2=Tableaus(middle), 3=Stock(bottom)]");
	} while (choosenBoardArea != 1 && choosenBoardArea != 2 && choosenBoardArea != 3);
	switch (choosenBoardArea) {
	case 1:
		do {
			choosenStack = this->IO.readInt(
					"Enter the Foundation you want to access [1 .. " + std::to_string(this->board->getSuitNumberMax()) + "]");
		} while (choosenStack < 1 || choosenStack >= this->board->getSuitNumberMax());
		sourceStack = this->board->getFoundation(choosenStack);
		if (sourceStack->getCardsNumber()) {
			sourceCard = sourceStack->getLastCard();
			if (((Foundation *) sourceStack)->canRemove(sourceCard)) {
				result = true;
			}
		}
		break;
	case 2:
		do {
			choosenStack = this->IO.readInt(
					"Enter the Tableau you want to access [1 .. " + std::to_string(this->board->getTableausNumberMax()) + "]");
		} while (choosenStack < 1 || choosenStack > this->board->getTableausNumberMax());
		sourceStack = this->board->getTableau(choosenStack - 1);
		if (sourceStack->getCardsNumber()) {
			do {
				choosenCard = this->IO.readInt(
						"Enter the card you want to access [1 .. "
								+ std::to_string(
										sourceStack->getCardsNumber() - ((Tableau *) sourceStack)->getHiddenCardsNumber()) + "]");
			} while (choosenCard < 1
					|| choosenCard > (sourceStack->getCardsNumber() - ((Tableau *) sourceStack)->getHiddenCardsNumber()));
			sourceCard = sourceStack->getCard(choosenCard);
			if (((Tableau *) sourceStack)->canRemove(sourceCard)) {
				result = true;
			}
		}
		break;
	case 3:
		sourceStack = this->board->getStock();
		if ((((Stock *) sourceStack)->getVisibleCardsNumber() > 0) && (sourceStack->getCardsNumber() > 0)) {
			sourceCard = ((Stock *) sourceStack)->getLastCard();
			if (((Stock *) sourceStack)->canRemove(sourceCard)) {
				result = true;
			}
		}
		break;
	}
	return result;
}

bool Controller::selectStackToPut(StackAddable *&targetStack, Cards::Card *&sourceCard) {

	int choosenBoardArea;
	int choosenStack;
	bool result = true;
	do {
		choosenBoardArea = this->IO.readInt(
				"Enter the section you want to insert your card(s) [1=Foundations(top), 2=Tableau(middle)]");
	} while (choosenBoardArea != 1 && choosenBoardArea != 2);
	switch (choosenBoardArea) {
	case 1:
		do {
			choosenStack = this->IO.readInt(
					"Enter the Foundation where you want to insert your card(s) [1 .. "
							+ std::to_string(this->board->getSuitNumberMax()) + "]");
		} while (choosenStack < 1 || choosenStack > this->board->getSuitNumberMax());
		targetStack = this->board->getFoundation(choosenStack - 1);
		if (!((Foundation *) targetStack)->canAdd(sourceCard)) {
			result = false;
		}
		break;
	case 2:
		do {
			choosenStack = this->IO.readInt(
					"Enter the Tableau where you want to insert your card(s) [1 .. "
							+ std::to_string(this->board->getTableausNumberMax()) + "]");
		} while (choosenStack < 1 || choosenStack > this->board->getTableausNumberMax());
		targetStack = this->board->getTableau(choosenStack - 1);
		if (!((Tableau *) targetStack)->canAdd(sourceCard)) {
			result = false;
		}
		break;
	}
	return result;
}
