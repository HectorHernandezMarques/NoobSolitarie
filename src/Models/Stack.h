#ifndef STACK_H_
#define STACK_H_

#include "../Utils/Stack.h"

#include "Cards/Card.h"

namespace Models{

class Stack {
protected:
	Utils::Stack<Cards::Card> stack;
	virtual Utils::Node<Cards::Card>& remove(int index) = 0;

public:
	Stack();
	Stack(Utils::Node<Cards::Card> &card);
	virtual ~Stack();

	void add(Utils::Node<Cards::Card> &card);
	virtual bool canRemove(Cards::Card &card) = 0;
	Utils::Node<Cards::Card>& remove(Cards::Card &card);

	virtual Cards::Card& getCard(int index);
	virtual Cards::Card& getLastCard();
	int getCardsNumber();
};

} /* namespace Models */

#endif /* STACK_H_ */
