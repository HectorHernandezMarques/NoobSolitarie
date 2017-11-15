#ifndef BOARD_H_
#define BOARD_H_

#include "Deck.h"
#include "Tableau.h"
#include "Foundation.h"
#include "Stock.h"

namespace Models {

class Board {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	int tableausNumberMax;
	Deck deck;

	Tableau *tableau;
	Foundation *foundation;
	Stock stock;

public:
	Board(int suitNumberMax, int cardsPerSuitMax, int tableausNumberMax, int stockVisibleCardsMax);
	virtual ~Board();

	bool canFlip();
	void flip();

	int getCardsPerSuitMax();
	int getSuitNumberMax();
	int getTableausNumberMax();
	Deck& getDeck();
	Tableau& getTableau(int index);
	Foundation& getFoundation(int index);
	Stock& getStock();
	int getVisibleCardsNumberFromTableau(int index);
};

} /* namespace Models */

#endif /* BOARD_H_ */
