/*
 * MoveController.h
 *
 *  Created on: Nov 4, 2017
 *      Author: eherhes
 */

#ifndef CONTROLLERS_MOVECONTROLLER_H_
#define CONTROLLERS_MOVECONTROLLER_H_

#include "Controller.h"

namespace Controllers {

class MoveController : public Controller{
public:
	MoveController(Models::Board &board);
	virtual ~MoveController();

	void control();
	bool selectStackToTake(Models::Stack *&sourceStack, Models::Cards::Card *&sourceCard);
	bool selectStackToPut(Models::StackAddable *&targetStack, Models::Cards::Card *&sourceCard);
};

} /* namespace Controller */

#endif /* CONTROLLERS_MOVECONTROLLER_H_ */
