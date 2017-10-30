/*
 * NumberPoker.h
 *
 *  Created on: Oct 26, 2017
 *      Author: eherhes
 */

#ifndef CARDS_NUMBERPOKER_H_
#define CARDS_NUMBERPOKER_H_

#include "Number.h"

namespace Cards {

class NumberPoker: public Number {
public:
	NumberPoker() :
			Number() {
	}
	NumberPoker(int number, int maxNumber) :
			Number(number, maxNumber) {
	}
	virtual ~NumberPoker();

	std::string toString();
};

} /* namespace Cards */

#endif /* CARDS_NUMBERPOKER_H_ */
