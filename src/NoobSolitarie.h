/*
 * Game.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef NOOBSOLITARIE_H_
#define NOOBSOLITARIE_H_

#include "Controllers/Logic.h"
#include "Views/OperationControllerView.h"

class NoobSolitarie {
private:
	Controllers::Logic &logic;
	Views::OperationControllerView &operationControllerView;
public:
	NoobSolitarie(Controllers::Logic &logic, Views::OperationControllerView &operationControllerView);
	virtual ~NoobSolitarie();

	void run();
};

#endif /* NOOBSOLITARIE_H_ */
