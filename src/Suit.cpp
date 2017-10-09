/*
 * Suit.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Suit.h"

Suit::Suit() :
		Stack() {

}

Suit::Suit(Node<Card> *card) :
		Stack(card) {
}

Suit::~Suit() {
}

bool Suit::add(Node<Card> *card) {
	if (this->cardsNumber == 0)
			{
		if (card->getElement()->getNumber() == 0) {
			return this->Stack::add(card);
		} else {
			return false;
		}
	} else if (card->getElement()->getSuit()
			== this->cards->getElement()->getSuit()
			&& this->cards->getElement()->getNumber()
					== (card->getElement()->getNumber() - 1)
			&& card->getNextElement() == nullptr)
					{
		return this->Stack::add(card);
	} else {
		return false;
	}
}

bool Suit::canAdd(Node<Card> *card) {
	if (card) {
		if (this->cardsNumber == 0)
				{
			if (card->getElement()->getNumber() == 0) {
				return this->Stack::canAdd(card);
			} else {
				return false;
			}
		} else if (card->getElement()->getSuit()
				== this->cards->getElement()->getSuit()
				&& this->cards->getElement()->getNumber()
						== (card->getElement()->getNumber() - 1))
						{
			return this->Stack::canAdd(card);
		} else {
			return false;
		}
	} else {
		return false;
	}
}

Node<Card>* Suit::remove(int index) {
	if (index == 0 && this->cardsNumber) {
		Node<Card> *currentCard = this->cards;
		if (currentCard->getPreviousElement()) {
			currentCard->getPreviousElement()->setNextElement(nullptr);
		}
		this->cards = currentCard->getPreviousElement();
		this->cardsNumber--;

		return currentCard;
	}
	return nullptr;
}

Node<Card>* Suit::canRemove(int index) {
	if (index == 0 && this->cardsNumber) {
		Node<Card> *currentCard = this->cards;

		return currentCard;
	}
	return nullptr;
}

std::string Suit::print() {
	std::string result;

	if (this->cardsNumber) {
		result = "|" + this->cards->getElement()->print() + "|";
	} else {
		result = "|o|";
	}
	return result;
}
