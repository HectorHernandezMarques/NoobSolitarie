/*
 * Board.h
 *
 *  Created on: Oct 18, 2017
 *      Author: AntonioMontana
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Cards/Deck.tpp"
#include "Tableau.h"
#include "Foundation.h"
#include "Stock.h"

class Board {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	int tableausNumberMax;
	Cards::Deck<Cards::SuitPoker, Cards::NumberPoker> deck;

	Tableau *tableau;
	Foundation *foundation;
	Stock stock;

public:
	Board(int suitNumberMax, int cardsPerSuitMax, int tableausNumberMax, int stockVisibleCardsMax);
	virtual ~Board();

	std::string toString();

	int getCardsPerSuitMax() {
		return cardsPerSuitMax;
	}
	int getSuitNumberMax() {
		return suitNumberMax;
	}
	int getTableausNumberMax() {
		return tableausNumberMax;
	}
	Cards::Deck<Cards::SuitPoker, Cards::NumberPoker>* getDeck() {
		return &deck;
	}
	Tableau* getTableau(int index) {
		return &tableau[index];
	}
	Foundation* getFoundation(int index) {
		return &foundation[index];
	}
	Stock* getStock() {
		return &stock;
	}
};

#endif /* BOARD_H_ */
