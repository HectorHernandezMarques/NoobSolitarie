#ifndef MODELS_MEMENTO_BOARDMEMENTOCARETAKER_H_
#define MODELS_MEMENTO_BOARDMEMENTOCARETAKER_H_

#include "./BoardMemento.h"
#include <list>

namespace Models {
namespace Memento {

class BoardMementoCareTaker {
private:
	std::list<BoardMemento> boardMementos;
	std::list<BoardMemento>::iterator currentMemento;

public:
	BoardMementoCareTaker();
	virtual ~BoardMementoCareTaker();

	void addMemento(BoardMemento &boardMemento);
	bool hasPreviousMemento();
	bool hasNextMemento();
	BoardMemento& getPreviousMemento();
	BoardMemento& getNextMemento();
	void setPreviousMemento();
	void setNextMemento();
};

} /* namespace Memento */
} /* namespace Models */

#endif /* MODELS_MEMENTO_BOARDMEMENTOCARETAKER_H_ */
