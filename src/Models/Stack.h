#ifndef STACK_H_
#define STACK_H_

#include "../Utils/Stack.h"

#include "Cards/Card.h"

namespace Models{

class Stack {
protected:
	Utils::Stack<Cards::Card> stack;
	virtual Utils::Stack<Cards::Card>& remove(int index) = 0;

public:
	Stack();
	Stack(Utils::Stack<Cards::Card> &card);
	virtual ~Stack();

	void add(Cards::Card &card);
	void add(Utils::Stack<Cards::Card> &card);
	virtual bool canRemove(Cards::Card &card) = 0;
	Utils::Stack<Cards::Card>& remove(Cards::Card &card);

	virtual Cards::Card& getCard(int index);
	virtual Cards::Card& getLastCard();
	Utils::Stack<Cards::Card>& getUntilEnd(int index);
	virtual Utils::Stack<Cards::Card>& getVisibleCards() = 0;
	virtual int getVisibleCardsNumber() = 0;
	int getCardsNumber();
};

} /* namespace Models */

#endif /* STACK_H_ */
