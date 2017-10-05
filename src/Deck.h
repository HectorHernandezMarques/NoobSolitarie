/*
 * Deck.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef DECK_H_
#define DECK_H_

#include "Definitions.h"
#include "Card.h"

class Deck {
private:
	Card cards[SUIT_NUMBER][CARDS_PER_SUIT];
	bool servedCards[SUIT_NUMBER * CARDS_PER_SUIT] = {false};

public:
	Deck();
	virtual ~Deck();

	bool getServedCards(int index) { return servedCards[index]; }
	void setServedCards(int index, bool value) { this->servedCards[index] = value; }

	Card* getCard(int suit, int number) { return &cards[suit][number]; }
	Card* getCard(int index) { return &cards[index / CARDS_PER_SUIT][index % CARDS_PER_SUIT]; }
};

#endif /* DECK_H_ */
