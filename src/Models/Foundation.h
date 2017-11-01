#ifndef FOUNDATION_H_
#define FOUNDATION_H_

#include "StackAddable.h"

namespace Models{

class Foundation: public StackAddable {
private:
	Utils::Node<Cards::Card>& remove(int index);
public:
	Foundation();
	Foundation(Utils::Node<Cards::Card> &card);
	virtual ~Foundation();

	bool canAdd(Cards::Card &card);
	bool canRemove(Cards::Card &card);
	Utils::Node<Cards::Card>& remove(Cards::Card &card);

	Cards::Card& getCard();
};

} /* namespace Models */

#endif /* FOUNDATION_H_ */
