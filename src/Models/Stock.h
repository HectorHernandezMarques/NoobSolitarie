#ifndef STOCK_H_
#define STOCK_H_

#include "Stack.h"

namespace Models {

class Stock: public Stack {
private:
	int visibleCardsMax;
	int hiddenCardsNumber;
	int visibleCardsNumber;

	Utils::Node<Cards::Card>& remove(int index);

public:
	Stock(int visibleCardsMax);
	Stock(Utils::Node<Cards::Card> &cards, int visibleCardsMax);
	virtual ~Stock();

	bool canFlip();
	void flip();
	bool canRemove(Cards::Card &card);

	Cards::Card& getLastCard();
	int getVisibleCardsNumber();
	int getHiddenCardsNumber();
	void setHiddenCardsNumber(int hiddenCardsNumber);
};

} /* namespace Models */

#endif /* STOCK_H_ */
