/*
 * Controller.h
 *
 *  Created on: Oct 18, 2017
 *      Author: eherhes
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../Models/Board.h"
#include "../Utils/IO.h"

namespace Controllers {

class Controller {
protected:
	Models::Board *board;
	Utils::IO IO;

public:
	Controller(Models::Board &board);
	virtual ~Controller();

	virtual void control() = 0;
	void printBoard();
	void flipCard();
	void moveCard();
	bool selectStackToTake(Models::Stack *&sourceStack, Models::Cards::Card *&sourceCard);
	bool selectStackToPut(Models::StackAddable *&targetStack, Models::Cards::Card *&sourceCard);
	void putCard(Models::Cards::Card &card);
};

}  /* namespace Utils */

#endif /* CONTROLLER_H_ */
