#ifndef TABLEAU_H_
#define TABLEAU_H_

#include "./StackAddable.h"
#include "./Memento/TableauMemento.h"

namespace Models{

class Tableau: public StackAddable {
private:
	int hiddenCardsNumber;

	Utils::Stack<Cards::Card>& remove(int index);

public:
	Tableau();
	Tableau(Utils::Stack<Cards::Card> &card);
	virtual ~Tableau();

	bool canAdd(Utils::Stack<Cards::Card> &cards);
	bool canRemove(Cards::Card &card);
	bool canRemoveRelativeCards(int relativeIndex);

	void setHiddenCardsNumber(int hiddenCardsNumber);
	Utils::Stack<Cards::Card>& getRelativeCards(int relativeIndex);
	Utils::Stack<Cards::Card>& getVisibleCards();
	int getHiddenCardsNumber();
	int getVisibleCardsNumber();
	Memento::TableauMemento createMemento();
	void setMemento(Memento::TableauMemento &tableauMemento);

};

} /* namespace Models */

#endif /* TABLEAU_H_ */
