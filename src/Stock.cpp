/*
 * Stock.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Stock.h"

Stock::Stock(int visibleCardsMax) :
		Stack() {
	this->visibleCardsMax = visibleCardsMax;
	this->hiddenCardsNumber = 0;
	this->visibleCardsNumber = 0;
}

Stock::Stock(Utils::Node<Cards::Card> *card, int visibleCardsMax) :
		Stack(card) {
	assert(card);
	this->visibleCardsMax = visibleCardsMax;
	this->hiddenCardsNumber = this->getCardsNumber();
	this->visibleCardsNumber = 0;
}

Stock::~Stock() {
}

Utils::Node<Cards::Card> * Stock::remove(int index) {
	assert(index >= 0);
	assert(index < this->getCardsNumber());

	this->visibleCardsNumber--;
	return this->stack.remove(index);
}

bool Stock::canFlip() {
	return this->getCardsNumber();
}

void Stock::flip() {
	assert(this->canFlip());
	if (this->hiddenCardsNumber) {
		this->visibleCardsNumber =
				(this->hiddenCardsNumber > this->visibleCardsMax) ? this->visibleCardsMax : this->hiddenCardsNumber;
		this->hiddenCardsNumber =
				(this->hiddenCardsNumber > this->visibleCardsMax) ? this->hiddenCardsNumber - this->visibleCardsMax : 0;
	} else {
		this->visibleCardsNumber = 0;
		this->hiddenCardsNumber = this->getCardsNumber();
	}
}

bool Stock::canRemove(Cards::Card *card) {
	assert(card);

	int index = this->stack.getIndex(card);
	return (this->getCardsNumber() - this->hiddenCardsNumber - this->visibleCardsNumber) <= index
			&& index < (this->getCardsNumber() - this->hiddenCardsNumber);
}

std::string Stock::toString() {
	std::string result;

	if (this->getCardsNumber()) {
		if (this->hiddenCardsNumber) {
			result = "|X|  ";
		} else {
			result = "|o|  ";
		}
		for (int i = 0; i < this->visibleCardsNumber; i++) {
			result += "|" + this->stack.get(this->getCardsNumber() - this->hiddenCardsNumber - i - 1)->toString() + "|  ";
		}
		for (int i = 0; i < (this->visibleCardsMax - this->visibleCardsNumber); i++) {
			result += "|o|  ";
		}
	} else {
		result = "|o|   |o|  |o|  |o|  ";
	}
	result += "<<";
	return result;
}
