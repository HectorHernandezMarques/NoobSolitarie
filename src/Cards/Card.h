/*
 * Card.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef CARDS_CARD_H_
#define CARDS_CARD_H_

#include <cassert>
#include "Suit.h"
#include "Number.h"

namespace Cards {

class Card {
private:
	Suit *suit;
	Number *number;

public:
	Card();
	Card(Suit *suit, Number *number);
	virtual ~Card();

	std::string toString();

	void setSuit(Suit *suit) {
		this->suit = suit;
	}
	void setNumber(Number *number) {
		this->number = number;
	}

	Suit* getSuit() {
		return this->suit;
	}
	Number* getNumber() {
		return this->number;
	}
};

} /* namespace Cards */

#endif /* CARDS_CARD_H_ */
