/*
 * StartController.h
 *
 *  Created on: Nov 4, 2017
 *      Author: eherhes
 */

#ifndef CONTROLLERS_STARTCONTROLLER_H_
#define CONTROLLERS_STARTCONTROLLER_H_

#include "Controller.h"

namespace Controllers {

class StartController : public Controller{
public:
	StartController(Models::Board &board);
	virtual ~StartController();

	void control();
};

} /* namespace Controller */

#endif /* CONTROLLERS_STARTCONTROLLER_H_ */
