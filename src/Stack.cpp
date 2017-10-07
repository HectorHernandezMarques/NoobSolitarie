/*
 * Stack.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Stack.h"
#include "iostream"

Stack::Stack() {
	this->cards = new Node<Card>();
	this->cardsNumber = 0;
}

Stack::Stack(Node<Card> *card) {
	this->cards = card;
	int currentCardsNumber = 0;
	Node<Card> *currentCard = card;

	for (; currentCard; currentCardsNumber++) {
		currentCard = currentCard->getPreviousElement();
	}

	this->cardsNumber = currentCardsNumber;
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

bool Stack::add(Node<Card> *card) {
	int newCardsNumber = 1;

	if (this->cardsNumber) {
		this->cards->setNextElement(card); //linking last card to new card
	}

	card->setPreviousElement(this->cards); //linking new card(s) to last card

	this->cards = card;

	Node<Card> *currentCard = this->cards;
	while (currentCard->getNextElement()) //setting last card just in case there are several added cards
	{
		newCardsNumber++;
		currentCard = currentCard->getNextElement();
	}

	this->cardsNumber += newCardsNumber;
	this->cards = currentCard;

	return true;
}

bool Stack::checkAdd(Node<Card> *card) {
	if (card) {
		return true;
	} else {
		return false;
	}
}

Node<Card>* Stack::remove(int index) {
	if (index < this->cardsNumber && index >= 0) //if the card exist
			{
		Node<Card> *currentCard = this->cards;
		for (int i = 0; i < index; i++) //seeking the card wanted
				{
			currentCard = currentCard->getPreviousElement();
		}

		if (currentCard->getPreviousElement()) //if it's not the first card
		{
			currentCard->getPreviousElement()->setNextElement(
					currentCard->getNextElement()); //linking previous card with the next
		}
		if (currentCard->getNextElement()) //if it's not the last card
		{
			currentCard->getNextElement()->setPreviousElement(
					currentCard->getPreviousElement()); //linking the next card with the previous
		} else {
			this->cards = currentCard->getPreviousElement(); //setting last card if it's removed
		}

		this->cardsNumber--;

		currentCard->setNextElement(nullptr); //cleaning removed card links
		currentCard->setPreviousElement(nullptr);

		return currentCard;
	} else {
		return nullptr;
	}
}

Node<Card>* Stack::checkRemove(int index) {
	if (index < this->cardsNumber && index >= 0) //if the card exist
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

std::string Stack::print() {
	return "";
}
