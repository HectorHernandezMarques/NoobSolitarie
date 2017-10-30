/*
 * Card.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Card.h"

namespace Cards {

Card::Card() {
}

Card::Card(Suit *suit, Number *number) {
	assert(suit);
	assert(number);

	this->suit = suit;
	this->number = number;
}

Card::~Card() {
}

std::string Card::toString() {
	return this->suit->toString() + this->number->toString();
}

} /* namespace Cards */
