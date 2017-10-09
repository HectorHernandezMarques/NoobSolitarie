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
}

bool Stack::add(Node<Card> *card) {
	int newCardsNumber = 1;

	if (this->cardsNumber) {
		this->cards->setNextElement(card);
	}

	card->setPreviousElement(this->cards);

	this->cards = card;

	Node<Card> *currentCard = this->cards;
	while (currentCard->getNextElement())
	{
		newCardsNumber++;
		currentCard = currentCard->getNextElement();
	}

	this->cardsNumber += newCardsNumber;
	this->cards = currentCard;

	return true;
}

bool Stack::canAdd(Node<Card> *card) {
	if (card) {
		return true;
	} else {
		return false;
	}
}

Node<Card>* Stack::remove(int index) {
	if (index < this->cardsNumber && index >= 0)
			{
		Node<Card> *currentCard = this->cards;
		for (int i = 0; i < index; i++)
				{
			currentCard = currentCard->getPreviousElement();
		}

		if (currentCard->getPreviousElement())
		{
			currentCard->getPreviousElement()->setNextElement(
					currentCard->getNextElement());
		}
		if (currentCard->getNextElement())
		{
			currentCard->getNextElement()->setPreviousElement(
					currentCard->getPreviousElement());
		} else {
			this->cards = currentCard->getPreviousElement();
		}

		this->cardsNumber--;

		currentCard->setNextElement(nullptr);
		currentCard->setPreviousElement(nullptr);

		return currentCard;
	} else {
		return nullptr;
	}
}

Node<Card>* Stack::canRemove(int index) {
	if (index < this->cardsNumber && index >= 0)
			{
		Node<Card> *currentCard = this->cards;
		for (int i = 0; i < index; i++)
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
