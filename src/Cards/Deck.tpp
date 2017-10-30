/*
 * Deck.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef CARDS_DECK_H_
#define CARDS_DECK_H_

#include <time.h>
#include "Card.h"
#include "SuitPoker.h"
#include "NumberPoker.h"

namespace Cards {

template<class SuitType, class NumberType>
class Deck {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	Card **cards;
	int servedCardsNumber;
	bool *servedCards;
public:
	Deck(int suitNumberMax, int cardsPerSuitMax);
	virtual ~Deck() {
	}

	Card* getRandomCard();
	void resetDeck();
	bool isThereCardsToGive() {
		return (this->suitNumberMax * this->cardsPerSuitMax)
				> this->servedCardsNumber;
	}

	Card* getCard(int suit, int number) {
		return &cards[suit][number];
	}
	Card* getCard(int absoluteIndex) {
		return &cards[absoluteIndex / cardsPerSuitMax][absoluteIndex
				% cardsPerSuitMax];
	}
};

template<class SuitType, class NumberType> Deck<SuitType, NumberType>::Deck(
		int suitNumberMax, int cardsPerSuitMax) {
	assert(suitNumberMax > 0);
	assert(cardsPerSuitMax > 0);

	std::srand (time(NULL));
	this->suitNumberMax = suitNumberMax;
	this->cardsPerSuitMax = cardsPerSuitMax;
	this->cards = new Card*[this->suitNumberMax];
	for (int i = 0; i < this->suitNumberMax; ++i) {
		this->cards[i] = new Card[this->cardsPerSuitMax]();
	}
	for (int i = 0; i < this->suitNumberMax; i++) {
		for (int j = 0; j < this->cardsPerSuitMax; j++) {
			this->cards[i][j].setSuit(new SuitType(i));
			this->cards[i][j].setNumber(new NumberType(j, this->cardsPerSuitMax));
		}
	}
	this->servedCards = new bool[this->suitNumberMax * this->cardsPerSuitMax];
	this->resetDeck();
}

template<class SuitType, class NumberType> Card* Deck<SuitType, NumberType>::getRandomCard() {
	int nextCard = rand() % (this->suitNumberMax * this->cardsPerSuitMax);
	while (this->servedCards[nextCard]) {
		nextCard = (nextCard + 1)
				% (this->suitNumberMax * this->cardsPerSuitMax);
	}
	this->servedCardsNumber++;
	this->servedCards[nextCard] = true;
	return this->getCard(nextCard);
}

template<class SuitType, class NumberType> void Deck<SuitType, NumberType>::resetDeck() {
	this->servedCardsNumber = 0;
	for (int i = 0; i < (this->suitNumberMax * this->cardsPerSuitMax); i++) {
		this->servedCards[i] = false;
	}
}

} /* namespace Cards */

#endif /* CARDS_DECK_H_ */
