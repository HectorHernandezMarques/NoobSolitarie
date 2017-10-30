/*
 * Controller.h
 *
 *  Created on: Oct 18, 2017
 *      Author: eherhes
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Board.h"
#include "Utils/IO.h"

class Controller {
private:
	Board *board;
	Utils::IO IO;
public:
	Controller(Board *board);
	virtual ~Controller();

	void printBoard();
	void flipCard();
	void moveCard();
	bool selectStackToTake(Stack *&sourceStack, Cards::Card *&sourceCard);
	bool selectStackToPut(StackAddable *&targetStack, Cards::Card *&sourceCard);
	void putCard(Cards::Card *card);
};

#endif /* CONTROLLER_H_ */
