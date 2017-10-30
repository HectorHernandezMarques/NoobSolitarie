/*
 * StackAddable.h
 *
 *  Created on: Oct 25, 2017
 *      Author: eherhes
 */

#ifndef STACKADDABLE_H_
#define STACKADDABLE_H_

#include "Stack.h"

class StackAddable: public Stack {
public:
	StackAddable();
	StackAddable(Utils::Node<Cards::Card> *card);
	virtual ~StackAddable();

	virtual bool canAdd(Cards::Card *card) = 0;

};

#endif /* STACKADDABLE_H_ */
