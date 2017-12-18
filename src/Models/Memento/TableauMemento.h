#ifndef MODELS_MEMENTO_TABLEAUMEMENTO_H_
#define MODELS_MEMENTO_TABLEAUMEMENTO_H_

#include "../../Utils/Stack.h"
#include "../Cards/Card.h"

namespace Models{
namespace Memento{

class TableauMemento {
private:
	int hiddenCardsNumber;

	Utils::Stack<Cards::Card> cards;

public:
	TableauMemento(int hiddenCardsNumber, Utils::Stack<Cards::Card> &cards);
	TableauMemento(const TableauMemento &tableauMemento);
	virtual ~TableauMemento();

	int getHiddenCardsNumber();

	Utils::Stack<Cards::Card> getCards();
};

} /* namespace Memento */
} /* namespace Models */

#endif /* MODELS_MEMENTO_TABLEAUMEMENTO_H_ */
