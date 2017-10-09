/*
 * Game.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef NOOBSOLITARIE_H_
#define NOOBSOLITARIE_H_

#include "Stack.h"
#include "Definitions.h"
#include "Deck.h"

class Game {
private:
	Deck deck;

	Stack *pile[7];
	Stack *suit[SUIT_NUMBER];
	Stack *remainderDeck;

public:
	Game();
	virtual ~Game();

	void run();
	bool firstDecition(int *option);
	void secondDecition(int *option);
	std::string printGame();
};

#endif /* NOOBSOLITARIE_H_ */
