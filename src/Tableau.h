/*
 * Tableau.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef TABLEAU_H_
#define TABLEAU_H_

#include <string>
#include "StackAddable.h"

class Tableau: public StackAddable {
private:
	int hiddenCardsNumber;

	Utils::Node<Cards::Card>* remove(int index);

public:
	Tableau();
	Tableau(Utils::Node<Cards::Card> *card);
	virtual ~Tableau();

	bool canAdd(Cards::Card *card);
	bool canRemove(Cards::Card *card);
	std::string toString();

	Cards::Card* getCard(int relativeIndex);
	int getHiddenCardsNumber() {
		return this->hiddenCardsNumber;
	}
	void setHiddenCardsNumber(int hiddenCards) {
		this->hiddenCardsNumber = hiddenCards;
	}
};

#endif /* TABLEAU_H_ */
