/*
 * SuitPoker.h
 *
 *  Created on: Oct 26, 2017
 *      Author: eherhes
 */

#ifndef SUITPOKER_H_
#define SUITPOKER_H_

#include "Suit.h"

namespace Cards {

class SuitPoker: public Suit {
public:
	SuitPoker() :
			Suit() {
	}
	SuitPoker(int suit) :
			Suit(suit) {
	}
	virtual ~SuitPoker();

	std::string toString();
};

} /* namespace Cards */

#endif /* SUITPOKER_H_ */
