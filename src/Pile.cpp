/*
 * Pile.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Pile.h"
#include "Definitions.h"

Pile::Pile() :
		Stack() {
	this->hiddenCards = 0;
}

Pile::Pile(Node<Card> *card) :
		Stack(card) {
	this->hiddenCards = this->cardsNumber - 1;
}

Pile::~Pile() {
}

bool Pile::add(Node<Card> *card) {
	if (this->cardsNumber == 0) {
		if (card->getElement()->getNumber() == (CARDS_PER_SUIT - 1)) //Set a King in a Pile Stack Empty
				{
			return this->Stack::add(card);
		} else {
			return false;
		}
	} else if (this->cards->getElement()->getSuit() % 2
			!= card->getElement()->getSuit() % 2
			&& this->cards->getElement()->getNumber()
					== (card->getElement()->getNumber() + 1)) //Set a lower alternative color card
					{
		return this->Stack::add(card);
	} else {
		return false;
	}
}

bool Pile::checkAdd(Node<Card> *card) {
	if (card) {
		if (this->cardsNumber == 0) {
			if (card->getElement()->getNumber() == (CARDS_PER_SUIT - 1)) //Set a King in a Pile Stack Empty
					{
				return Stack::checkAdd(card);
			} else {
				return false;
			}
		} else if (this->cards->getElement()->getSuit() % 2
				!= card->getElement()->getSuit() % 2
				&& this->cards->getElement()->getNumber()
						== (card->getElement()->getNumber() + 1)) //Set a lower alternative color card
						{
			return Stack::checkAdd(card);
		} else {
			return false;
		}
	} else {
		return false;
	}
}

Node<Card>* Pile::remove(int index) {
	if (index < (this->cardsNumber - this->hiddenCards)) //if the card exist
			{
		int removedCardsNumber = 1;
		Node<Card> *currentCard = this->cards;
		for (int i = 0; i < index; i++) //seeking the card wanted
				{
			removedCardsNumber++;
			currentCard = currentCard->getPreviousElement();
		}

		if (currentCard->getPreviousElement()) //if it's not the first card
		{
			currentCard->getPreviousElement()->setNextElement(nullptr); //linking previous card nothing
		}

		this->cards = currentCard->getPreviousElement(); //setting last card

		currentCard->setPreviousElement(nullptr); //downlinking removed card(s)

		this->cardsNumber -= removedCardsNumber;

		this->hiddenCards =
				(this->cardsNumber == this->hiddenCards && this->hiddenCards > 0) ?
						this->hiddenCards - 1 : this->hiddenCards;

		return currentCard;
	} else {
		return nullptr;
	}
}

Node<Card>* Pile::checkRemove(int index) {
	if (index < (this->cardsNumber - this->hiddenCards)) //if the card exist
			{
		Node<Card> *currentCard = this->cards;
		for (int i = 0; i < index; i++) //seeking the card wanted
				{
			currentCard = currentCard->getPreviousElement();
		}

		return currentCard;
	} else {
		return nullptr;
	}
}

std::string Pile::print() {
	if (this->cardsNumber > 0) {
		std::string result = "|";
		Node<Card> *currentNode = this->cards;

		for (; currentNode->getPreviousElement();
				currentNode = currentNode->getPreviousElement())
			;

		for (int i = 0; i < this->cardsNumber; i++) {
			result = result + currentNode->getElement()->print() + "|";
			currentNode = currentNode->getNextElement();
		}

		return result;
	} else {
		return "|o|";
	}
}
