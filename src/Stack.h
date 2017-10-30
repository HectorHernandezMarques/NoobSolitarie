/*
 * Stack.h
 *
 *  Created on: Oct 23, 2017
 *      Author: eherhes
 */

#ifndef STACK_H_
#define STACK_H_

#include "Utils/Stack.tpp"
#include "Cards/Card.h"

class Stack {
protected:
	Utils::Stack<Cards::Card> stack;
	virtual Utils::Node<Cards::Card>* remove(int index) = 0;

public:
	Stack();
	Stack(Utils::Node<Cards::Card> *card);
	virtual ~Stack();

	void add(Utils::Node<Cards::Card> *card);
	virtual bool canRemove(Cards::Card *card) = 0;
	Utils::Node<Cards::Card>* remove(Cards::Card *card);
	virtual std::string toString() = 0;

	virtual Cards::Card* getCard(int index);
	virtual Cards::Card* getLastCard();
	int getCardsNumber() {
		return this->stack.getItemsNumber();
	}
};

#endif /* STACK_H_ */
