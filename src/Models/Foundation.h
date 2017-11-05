#ifndef FOUNDATION_H_
#define FOUNDATION_H_

#include "StackAddable.h"

namespace Models{

class Foundation: public StackAddable {
private:
	Utils::Stack<Cards::Card>& remove(int index);
public:
	Foundation();
	Foundation(Utils::Stack<Cards::Card> &card);
	virtual ~Foundation();

	bool canAdd(Cards::Card &card);
	bool canRemove(Cards::Card &card);

	Cards::Card& getRelativeCard();
};

} /* namespace Models */

#endif /* FOUNDATION_H_ */
