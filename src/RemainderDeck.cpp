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
	this->hiddenCards = 0;
	this->visibleCards = 0;
}

RemainderDeck::RemainderDeck(Node<Card> *card) :
		Stack(card) {
	this->hiddenCards = this->cardsNumber;
	this->visibleCards = 0;
}

RemainderDeck::~RemainderDeck() {
	// TODO Auto-generated destructor stub
}

bool RemainderDeck::add(Node<Card> *card) {
	if (this->cardsNumber) {
		if (this->hiddenCards) {
			this->visibleCards =
					(this->hiddenCards > GAME_MODE) ?
							GAME_MODE : this->hiddenCards;
			this->hiddenCards =
					(this->hiddenCards > GAME_MODE) ? this->hiddenCards - 3 : 0;
		} else {
			this->visibleCards = 0;
			this->hiddenCards = this->cardsNumber;
		}
	} else {
		return false;
	}
	return true;
}

bool RemainderDeck::checkAdd(Node<Card> *card) {
	if (this->cardsNumber) {
		return true;
	} else {
		return false;
	}
}

Node<Card>* RemainderDeck::remove(int index) {
	if (index == 0 && this->cardsNumber) {
		this->visibleCards =
				(this->visibleCards == 1) ? 1 : this->visibleCards - 1;
		return Stack::remove(this->cardsNumber - this->hiddenCards - 1);
	} else {
		return nullptr;
	}
}

Node<Card>* RemainderDeck::checkRemove(int index) {
	if (index == 0 && this->cardsNumber) {
		return Stack::checkRemove(this->cardsNumber - this->hiddenCards - 1);
	} else {
		return nullptr;
	}
}

std::string RemainderDeck::print() {
	std::string result;

	if (this->cardsNumber) {
		if (this->hiddenCards) {
			result = "|X|  ";
		} else {
			result = "|o|  ";
		}

		Node<Card> *currentNode = this->cards;

		for (int i = 0;
				i < this->cardsNumber - this->hiddenCards - this->visibleCards;
				i++) {
			currentNode = currentNode->getPreviousElement();
		}

		for (int i = 0; i < this->visibleCards; i++) {
			result += "|" + currentNode->getElement()->print() + "|  ";
			currentNode = currentNode->getPreviousElement();
		}

		for (int i = 0; i < (GAME_MODE - this->visibleCards); i++) {
			result += "|o|  ";
		}
	} else {
		result = "|o|   |o|  |o|  |o|  ";
	}

	result += "<<";

	return result;
}
