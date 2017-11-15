/*
 * Game.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "NoobSolitarie.h"

NoobSolitarie::NoobSolitarie(Controllers::Logic &logic, Views::OperationControllerView &operationControllerView) :
		logic(logic), operationControllerView(operationControllerView) {
}

NoobSolitarie::~NoobSolitarie() {
}

void NoobSolitarie::run() {
	Controllers::OperationController *operationController;

	do {
		operationController = &(this->logic.getOperationController());
		if (operationController != nullptr) {
			this->operationControllerView.interact(*operationController);
		}
	} while (operationController != nullptr);
}
