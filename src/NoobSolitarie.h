/*
 * Game.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef NOOBSOLITARIE_H_
#define NOOBSOLITARIE_H_

#include "IO.h"
#include "Stack.h"
#include "Definitions.h"
#include "Deck.h"

class NoobSolitarie {
private:
	Deck deck;

	Stack *pile[7];
	Stack *suit[SUIT_NUMBER];
	Stack *remainderDeck;

	IO IO;

public:
	NoobSolitarie();
	virtual ~NoobSolitarie();

	void run();
	bool firstDecition(int *option);
	void secondDecition(int *option);
	std::string toString();
};

#endif /* NOOBSOLITARIE_H_ */
