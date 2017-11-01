#ifndef BOARD_H_
#define BOARD_H_

#include "Cards/Deck.h"
#include "Tableau.h"
#include "Foundation.h"
#include "Stock.h"

namespace Models {

class Board {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	int tableausNumberMax;
	Cards::Deck deck;

	Tableau *tableau;
	Foundation *foundation;
	Stock stock;

public:
	Board(int suitNumberMax, int cardsPerSuitMax, int tableausNumberMax, int stockVisibleCardsMax);
	virtual ~Board();

	std::string toString();

	int getCardsPerSuitMax();
	int getSuitNumberMax();
	int getTableausNumberMax();
	Cards::Deck& getDeck();
	Tableau& getTableau(int index);
	Foundation& getFoundation(int index);
	Stock& getStock();
};

} /* namespace Models */

#endif /* BOARD_H_ */
