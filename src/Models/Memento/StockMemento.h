#ifndef MODELS_MEMENTO_STOCKMEMENTO_H_
#define MODELS_MEMENTO_STOCKMEMENTO_H_

#include "../../Utils/Stack.h"
#include "../Cards/Card.h"

namespace Models {
namespace Memento {

class StockMemento {
private:
	int visibleCardsMax;
	int hiddenCardsNumber;
	int visibleCardsNumber;

	Utils::Stack<Cards::Card> cards;

public:
	StockMemento(int visibleCardsMax, int hiddenCardsNumber, int visibleCardsNumber, Utils::Stack<Cards::Card> &cards);
	StockMemento(const StockMemento& stockMemento);
	virtual ~StockMemento();

	int getVisibleCardsMax();
	int getHiddenCardsNumber();
	int getVisibleCardsNumber();

	Utils::Stack<Cards::Card> getCards();
};

} /* namespace Memento */
} /* namespace Models */

#endif /* MODELS_MEMENTO_STOCKMEMENTO_H_ */
