#ifndef STACKADDABLE_H_
#define STACKADDABLE_H_

#include "Stack.h"

namespace Models{

class StackAddable: public Stack {
public:
	StackAddable();
	StackAddable(Utils::Stack<Cards::Card> &card);
	virtual ~StackAddable();

	virtual bool canAdd(Cards::Card &card) = 0;
};

} /* namespace Models */

#endif /* STACKADDABLE_H_ */
