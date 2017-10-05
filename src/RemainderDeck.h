/*
 * RemainderDeck.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef REMAINDERDECK_H_
#define REMAINDERDECK_H_

#include "Stack.h"

class RemainderDeck: public Stack {
private:
	int hiddenCards;
	int visibleCards;

public:
	RemainderDeck();
	RemainderDeck(Node<Card> *cards);
	virtual ~RemainderDeck();

	bool add(Node<Card> *card);
	bool checkAdd(Node<Card> *card);
	Node<Card>* remove(int index);
	Node<Card>* checkRemove(int index);
	std::string print();
};

#endif /* REMAINDERDECK_H_ */
