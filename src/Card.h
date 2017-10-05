/*
 * Card.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card {
private:
	int suit;
	int number;

public:
	Card();
	Card(int suit, int number);
	virtual ~Card();

	std::string print();
	char printSuit();
	std::string printNumber();

	void setSuit(int suit) { this->suit = suit; }
	void setNumber(int number) { this->number = number; }

	int getSuit() { return this->suit; }
	int getNumber() { return this->number; }
};

#endif /* CARD_H_ */
