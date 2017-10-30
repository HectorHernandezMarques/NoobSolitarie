/*
 * Foundation.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Foundation.h"

Foundation::Foundation() :
		StackAddable() {
}

Foundation::Foundation(Utils::Node<Cards::Card> *card) :
		StackAddable(card) {
}

Foundation::~Foundation() {
}

Utils::Node<Cards::Card>* Foundation::remove(int index) {
	assert(index >= 0);
	assert(index < this->getCardsNumber());

	return this->stack.remove(index);
}

bool Foundation::canAdd(Cards::Card *card) {
	assert(card);
	bool result = false;
	if (this->getCardsNumber() == 0) {
		result = card->getNumber()->getNumber() == 0;
	} else {
		result = *card->getSuit() == *this->stack.getLast()->getSuit()
				&& card->getNumber()->isNextNumberOf(this->stack.getLast()->getNumber());
	}
	return result;
}

bool Foundation::canRemove(Cards::Card *card) {
	assert(card);

	int index = this->stack.getIndex(card);
	return index == (this->getCardsNumber() - 1);
}

std::string Foundation::toString() {
	std::string result;
	if (this->getCardsNumber()) {
		result = "|" + this->stack.getLast()->toString() + "|";
	} else {
		result = "|o|";
	}
	return result;
}
