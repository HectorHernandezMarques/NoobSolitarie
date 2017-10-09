/*
 * Pile.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef PILE_H_
#define PILE_H_

#include <string>

#include "Stack.h"

class Pile: public Stack {
private:
	int hiddenCardsNumber;

public:
	Pile();
	Pile(Node<Card> *card);
	virtual ~Pile();

	bool add(Node<Card> *card);
	bool canAdd(Node<Card> *card);
	Node<Card>* remove(int index);
	Node<Card>* canRemove(int index);
	std::string print();

	int getHiddenCardsNumber() {
		return this->hiddenCardsNumber;
	}
	void setHiddenCardsNumber(int hiddenCards) {
		this->hiddenCardsNumber = hiddenCards;
	}
};

#endif /* PILE_H_ */
