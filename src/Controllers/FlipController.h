/*
 * FlipController.h
 *
 *  Created on: Nov 4, 2017
 *      Author: eherhes
 */

#ifndef CONTROLLERS_FLIPCONTROLLER_H_
#define CONTROLLERS_FLIPCONTROLLER_H_

#include "Controller.h"

namespace Controllers {

class FlipController : public Controller{
public:
	FlipController(Models::Board &board);
	virtual ~FlipController();

	void control();
};

} /* namespace Controller */

#endif /* CONTROLLERS_FLIPCONTROLLER_H_ */
