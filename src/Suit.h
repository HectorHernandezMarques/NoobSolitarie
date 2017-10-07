/*
 * Suit.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef SUIT_H_
#define SUIT_H_

#include "Stack.h"
#include <string>

class Suit: public Stack {

public:
	Suit();
	Suit(Node<Card> *card);
	virtual ~Suit();

	bool add(Node<Card> *card);
	bool checkAdd(Node<Card> *card);
	Node<Card>* remove(int index);
	Node<Card>* checkRemove(int index);
	std::string print();
};

#endif /* SUIT_H_ */
