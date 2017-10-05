/*
 * Card.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "Card.h"

Card::Card() {
	this->suit = 0;
	this->number = 0;
}

Card::Card(int suit, int number) {
	this->suit = suit;
	this->number = number;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

std::string Card::print() {
	std::string result;

	result = this->printSuit();
	result += this->printNumber();

	return result;
}

char Card::printSuit() {
	switch(this->suit)
	{
	case 0:
		return 3;

	case 1:
		return 5;

	case 2:
		return 4;

	case 3:
		return 6;

	default:
		return 3+this->suit;

	}
}

std::string Card::printNumber() {
	switch(this->number)
	{
	case 0:
		return "A";

	case 10:
		return "J";

	case 11:
		return "Q";

	case 12:
		return "K";

	default:
		return std::to_string(this->number + 1);

	}
}
