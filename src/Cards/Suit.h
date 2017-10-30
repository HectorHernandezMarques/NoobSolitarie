/*
 * Suit.h
 *
 *  Created on: Oct 22, 2017
 *      Author: eherhes
 */

#ifndef SUIT_H_
#define SUIT_H_

#include <string>

namespace Cards {

class Suit {
private:
protected:
	int suit;
public:
	Suit();
	Suit(int suit);
	virtual ~Suit();

	bool isSameParityOf(Suit *suit) {
		return (this->suit % 2) == (suit->suit % 2);
	}
	virtual std::string toString() = 0;

	bool operator==(const Suit &suit) {
		return this->suit == suit.suit;
	}
};

} /* namespace Cards */

#endif /* SUIT_H_ */
