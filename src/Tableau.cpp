/*
 * Tableau.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Tableau.h"

Tableau::Tableau() :
		StackAddable() {
	this->hiddenCardsNumber = 0;
}

Tableau::Tableau(Utils::Node<Cards::Card> *card) :
		StackAddable(card) {
	assert(card);

	this->hiddenCardsNumber = this->getCardsNumber() - 1;
}

Tableau::~Tableau() {
}

Utils::Node<Cards::Card>* Tableau::remove(int index) {
	assert(index >= 0);
	assert(index < this->getCardsNumber());

	this->hiddenCardsNumber =
			(index == this->hiddenCardsNumber && this->hiddenCardsNumber > 0) ?
					this->hiddenCardsNumber - 1 : this->hiddenCardsNumber;

	return this->stack.removeUntilEnd(index);
}

bool Tableau::canAdd(Cards::Card *card) {
	assert(card);

	bool result = false;
	if (this->getCardsNumber()) {
		result = !card->getSuit()->isSameParityOf(this->stack.getLast()->getSuit())
				&& this->stack.getLast()->getNumber()->isNextNumberOf(card->getNumber());
	} else {
		result = card->getNumber()->isLastNumber();
	}
	return result;
}

bool Tableau::canRemove(Cards::Card *card) {
	assert(card);

	int index = this->stack.getIndex(card);
	return this->hiddenCardsNumber <= index && index < this->getCardsNumber();
}

std::string Tableau::toString() {
	std::string result;
	if (this->getCardsNumber() > 0) {
		result = "|";
		for (int i = 0; i < this->getCardsNumber(); i++) {
			result = result + (this->stack.get(i))->toString() + "|";
		}
	} else {
		result = "|o|";
	}
	return result;
}

Cards::Card* Tableau::getCard(int relativeIndex) {
	int absoluteIndex = this->getCardsNumber() - relativeIndex;
	return stack.get(absoluteIndex);
}
