/*
 * Stack.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef STACK_H_
#define STACK_H_

#include "Node.h"
#include "Card.h"
#include <string>

class Stack {
private:

protected:
	Node<Card> *cards;
	int cardsNumber = 0;

public:
	Stack();
	Stack(Node<Card> *card);
	virtual ~Stack();

	virtual bool add(Node<Card> *card);
	virtual bool canAdd(Node<Card> *card);
	virtual Node<Card>* remove(int index);
	virtual Node<Card>* canRemove(int index);
	virtual std::string print();

	int getCardsNumber() {
		return this->cardsNumber;
	}
	void setCardsNumber(int cardsNumber) {
		this->cardsNumber = cardsNumber;
	}
};

#endif /* STACK_H_ */
