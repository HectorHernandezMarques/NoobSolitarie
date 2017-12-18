#ifndef FOUNDATION_H_
#define FOUNDATION_H_

#include "StackAddable.h"
#include "./Memento/FoundationMemento.h"

namespace Models{

class Foundation: public StackAddable {
private:
	Utils::Stack<Cards::Card>& remove(int index);
public:
	Foundation();
	Foundation(Utils::Stack<Cards::Card> &card);
	virtual ~Foundation();

	bool canAdd(Utils::Stack<Cards::Card> &cards);
	bool canRemove(Cards::Card &card);
	bool canRemoveRelativeCards();

	Utils::Stack<Cards::Card>& getRelativeCards();
	Utils::Stack<Cards::Card>& getVisibleCards();
	int getVisibleCardsNumber();
	Memento::FoundationMemento createMemento();
	void setMemento(Memento::FoundationMemento &foundationMemento);

};

} /* namespace Models */

#endif /* FOUNDATION_H_ */
