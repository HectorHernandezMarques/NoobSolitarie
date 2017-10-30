/*
 * Game.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "NoobSolitarie.h"

NoobSolitarie::NoobSolitarie() :
		IO(), board(SUIT_NUMBER, CARDS_PER_SUIT, PILES_NUMBER, GAME_MODE), controller(&this->board) {

}

NoobSolitarie::~NoobSolitarie() {
}

void NoobSolitarie::run() {
	int option;
	for (;;) {
		this->controller.printBoard();
		option = this->IO.readInt("Enter the action you want to do [1=Move Card, 2=Flip Cards]");
		switch (option) {
		case 1:
			this->controller.moveCard();
			break;
		case 2:
			this->controller.flipCard();
			break;
		}
	}
}

std::string NoobSolitarie::toString() {
	return this->board.toString();
}
