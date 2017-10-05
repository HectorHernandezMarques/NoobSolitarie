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
	int hiddenCards;

public:
	Pile();
	Pile(Node<Card> *card);
	virtual ~Pile();

	bool add(Node<Card> *card);
	bool checkAdd(Node<Card> *card);
	Node<Card>* remove(int index);
	Node<Card>* checkRemove(int index);
	std::string print();

	int getHiddenCards() { return this->hiddenCards; }
	void setHiddenCards(int hiddenCards) { this->hiddenCards = hiddenCards; }
};

#endif /* PILE_H_ */
