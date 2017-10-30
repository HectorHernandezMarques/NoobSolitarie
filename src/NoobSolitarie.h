/*
 * Game.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef NOOBSOLITARIE_H_
#define NOOBSOLITARIE_H_

#include <iostream>
#include "Utils/IO.h"
#include "Board.h"
#include "Controller.h"
#include "Definitions.h"

class NoobSolitarie {
private:
	Utils::IO IO;
	Board board;
	Controller controller;

public:
	NoobSolitarie();
	virtual ~NoobSolitarie();

	void run();
	std::string toString();
};

#endif /* NOOBSOLITARIE_H_ */
