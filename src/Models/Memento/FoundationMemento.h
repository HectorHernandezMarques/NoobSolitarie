#ifndef MODELS_MEMENTO_FOUNDATIONMEMENTO_H_
#define MODELS_MEMENTO_FOUNDATIONMEMENTO_H_

#include "../../Utils/Stack.h"
#include "../Cards/Card.h"

namespace Models {
namespace Memento {

class FoundationMemento {
private:
	Utils::Stack<Cards::Card> cards;

public:
	FoundationMemento(Utils::Stack<Cards::Card> &cards);
	FoundationMemento(const FoundationMemento& foundationMemento);
	virtual ~FoundationMemento();

	Utils::Stack<Cards::Card> getCards();
};

} /* namespace Memento */
} /* namespace Models */

#endif /* MODELS_MEMENTO_FOUNDATIONMEMENTO_H_ */
