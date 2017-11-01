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
#include "Models/Board.h"
#include "Controllers/Controller.h"
#include "Definitions.h"

class NoobSolitarie {
private:
	Utils::IO IO;
	Models::Board board;
	Controllers::Controller controller;

public:
	NoobSolitarie();
	virtual ~NoobSolitarie();

	void run();
};

#endif /* NOOBSOLITARIE_H_ */
