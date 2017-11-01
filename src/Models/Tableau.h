#ifndef TABLEAU_H_
#define TABLEAU_H_

#include <string>
#include "StackAddable.h"

namespace Models{

class Tableau: public StackAddable {
private:
	int hiddenCardsNumber;

	Utils::Node<Cards::Card>& remove(int index);

public:
	Tableau();
	Tableau(Utils::Node<Cards::Card> &card);
	virtual ~Tableau();

	bool canAdd(Cards::Card &card);
	bool canRemove(Cards::Card &card);

	Cards::Card& getCard(int relativeIndex);
	int getHiddenCardsNumber();
	void setHiddenCardsNumber(int hiddenCardsNumber);
};

} /* namespace Models */

#endif /* TABLEAU_H_ */
