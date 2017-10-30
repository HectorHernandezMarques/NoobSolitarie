/*
 * Stock.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef STOCK_H_
#define STOCK_H_

#include "Stack.h"

class Stock: public Stack {
private:
	int visibleCardsMax;
	int hiddenCardsNumber;
	int visibleCardsNumber;

	Utils::Node<Cards::Card>* remove(int index);

public:
	Stock(int visibleCardsMax);
	Stock(Utils::Node<Cards::Card> *cards, int visibleCardsMax);
	virtual ~Stock();

	bool canFlip();
	void flip();
	bool canRemove(Cards::Card *card);
	std::string toString();

	Cards::Card* getLastCard() {
		return this->stack.get(this->getCardsNumber() - this->hiddenCardsNumber - this->visibleCardsNumber);
	}

	int getVisibleCardsNumber() {
		return visibleCardsNumber;
	}
	int getHiddenCardsNumber() {
		return hiddenCardsNumber;
	}
	void setHiddenCardsNumber(int hiddenCardsNumber) {
		this->hiddenCardsNumber = hiddenCardsNumber;
	}
};

#endif /* STOCK_H_ */
