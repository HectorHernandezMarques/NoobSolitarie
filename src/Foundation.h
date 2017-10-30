/*
 * Foundation.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef FOUNDATION_H_
#define FOUNDATION_H_

#include "StackAddable.h"

class Foundation: public StackAddable {
private:
	Utils::Node<Cards::Card>* remove(int index);
public:
	Foundation();
	Foundation(Utils::Node<Cards::Card> *card);
	virtual ~Foundation();

	bool canAdd(Cards::Card *card);
	bool canRemove(Cards::Card *card);
	Utils::Node<Cards::Card>* remove(Cards::Card *card);
	std::string toString();

	Cards::Card* getCard() {
		return stack.get(this->getCardsNumber() - 1);
	}
};

#endif /* FOUNDATION_H_ */
