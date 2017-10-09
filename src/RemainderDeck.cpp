/*
 * RemainderDeck.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "RemainderDeck.h"
#include "Definitions.h"

#include "iostream"

RemainderDeck::RemainderDeck() :
		Stack() {
	this->hiddenCardsNumber = 0;
	this->visibleCardsNumber = 0;
}

RemainderDeck::RemainderDeck(Node<Card> *card) :
		Stack(card) {
	this->hiddenCardsNumber = this->cardsNumber;
	this->visibleCardsNumber = 0;
}

RemainderDeck::~RemainderDeck() {
	// TODO Auto-generated destructor stub
}

bool RemainderDeck::add(Node<Card> *card) {
	if (this->cardsNumber) {
		if (this->hiddenCardsNumber) {
			this->visibleCardsNumber =
					(this->hiddenCardsNumber > GAME_MODE) ?
							GAME_MODE : this->hiddenCardsNumber;
			this->hiddenCardsNumber =
					(this->hiddenCardsNumber > GAME_MODE) ? this->hiddenCardsNumber - 3 : 0;
		} else {
			this->visibleCardsNumber = 0;
			this->hiddenCardsNumber = this->cardsNumber;
		}
	} else {
		return false;
	}
	return true;
}

bool RemainderDeck::canAdd(Node<Card> *card) {
	if (this->cardsNumber) {
		return true;
	} else {
		return false;
	}
}

Node<Card>* RemainderDeck::remove(int index) {
	if (index == 0 && this->cardsNumber) {
		this->visibleCardsNumber =
				(this->visibleCardsNumber == 1) ? 1 : this->visibleCardsNumber - 1;
		return Stack::remove(this->cardsNumber - this->hiddenCardsNumber - 1);
	} else {
		return nullptr;
	}
}

Node<Card>* RemainderDeck::canRemove(int index) {
	if (index == 0 && this->cardsNumber) {
		return Stack::canRemove(this->cardsNumber - this->hiddenCardsNumber - 1);
	} else {
		return nullptr;
	}
}

std::string RemainderDeck::print() {
	std::string result;

	if (this->cardsNumber) {
		if (this->hiddenCardsNumber) {
			result = "|X|  ";
		} else {
			result = "|o|  ";
		}

		Node<Card> *currentNode = this->cards;

		for (int i = 0;
				i < this->cardsNumber - this->hiddenCardsNumber - this->visibleCardsNumber;
				i++) {
			currentNode = currentNode->getPreviousElement();
		}

		for (int i = 0; i < this->visibleCardsNumber; i++) {
			result += "|" + currentNode->getElement()->print() + "|  ";
			currentNode = currentNode->getPreviousElement();
		}

		for (int i = 0; i < (GAME_MODE - this->visibleCardsNumber); i++) {
			result += "|o|  ";
		}
	} else {
		result = "|o|   |o|  |o|  |o|  ";
	}

	result += "<<";

	return result;
}
