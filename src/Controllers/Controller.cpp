/*
 * Controller.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: eherhes
 */

#include "Controller.h"

namespace Controllers {

Controller::Controller(Models::Board &board) {
	this->board = &board;
}

Controller::~Controller() {

}
}  /* namespace Utils */
