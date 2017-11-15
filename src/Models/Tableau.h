#ifndef TABLEAU_H_
#define TABLEAU_H_

#include <string>
#include "StackAddable.h"

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
};

} /* namespace Models */

#endif /* TABLEAU_H_ */
