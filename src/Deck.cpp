/*
 * Deck.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Deck.h"

Deck::Deck() {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < SUIT_NUMBER; i++) {
		for (int j = 0; j < CARDS_PER_SUIT; j++) {
			this->cards[i][j].setSuit(i);
			this->cards[i][j].setNumber(j);
		}
	}
}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

