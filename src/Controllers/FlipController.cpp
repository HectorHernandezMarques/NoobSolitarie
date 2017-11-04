/*
 * FlipController.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: eherhes
 */

#include "FlipController.h"

namespace Controllers {

FlipController::FlipController(Models::Board &board) : Controller(board){
}

FlipController::~FlipController() {
}

void FlipController::control(){
	if (this->board->getStock().canFlip()) {
		this->board->getStock().flip();
	} else {
		this->IO.writeln("Can flip the stock");
	}
}

} /* namespace Controller */
