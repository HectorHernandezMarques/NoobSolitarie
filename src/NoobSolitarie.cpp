/*
 * Game.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "NoobSolitarie.h"

NoobSolitarie::NoobSolitarie() :
		IO(), board(SUIT_NUMBER, CARDS_PER_SUIT, PILES_NUMBER, GAME_MODE), startController(this->board), moveController(this->board), flipController(this->board) {

}

NoobSolitarie::~NoobSolitarie() {
}

void NoobSolitarie::run() {
	int option;
	for (;;) {
		this->startController.control();
		option = this->IO.readInt("Enter the action you want to do [1=Move Card, 2=Flip Cards]");
		switch (option) {
		case 1:
			this->moveController.control();
			break;
		case 2:
			this->flipController.control();
			break;
		}
	}
}
