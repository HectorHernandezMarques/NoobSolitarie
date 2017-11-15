/*
 * View.h
 *
 *  Created on: Nov 6, 2017
 *      Author: eherhes
 */

#ifndef VIEWS_OPERATIONCONTROLLERVIEW_H_
#define VIEWS_OPERATIONCONTROLLERVIEW_H_

#include "../Controllers/OperationController.h"

namespace Views {

class OperationControllerView {
public:
	virtual void interact(Controllers::OperationController &operationController) = 0;
};

} /* namespace Views */

#endif /* VIEWS_OPERATIONCONTROLLERVIEW_H_ */
