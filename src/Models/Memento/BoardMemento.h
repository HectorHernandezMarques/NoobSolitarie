#ifndef MODELS_MEMENTO_BOARDMEMENTO_H_
#define MODELS_MEMENTO_BOARDMEMENTO_H_

#include "./TableauMemento.h"
#include "./FoundationMemento.h"
#include "./StockMemento.h"
#include <list>

namespace Models {
namespace Memento {

class BoardMemento {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	int tableausNumberMax;

	std::list<TableauMemento> tableauMementos;
	std::list<FoundationMemento> foundationMementos;
	StockMemento stockMemento;

public:
	BoardMemento(int suitNumberMax, int cardsPerSuitMax, int tableausNumberMax, Memento::StockMemento &stockMemento);
	BoardMemento(const BoardMemento &boardMemento);
	virtual ~BoardMemento();

	void addTableauMemento(TableauMemento &tableauMemento);
	void addFoundationMemento(FoundationMemento &foundationMemento);

	int getSuitNumberMax();
	int getCardsPerSuitMax();
	int getTableausNumberMax();
	std::list<TableauMemento>::iterator getTableauMementosBegin();
	std::list<TableauMemento>::iterator getTableauMementosEnd();
	std::list<FoundationMemento>::iterator getFoundationMementosBegin();
	std::list<FoundationMemento>::iterator getFoundationMementosEnd();
	StockMemento& getStockMemento();
};

} /* namespace Memento */
} /* namespace Models */

#endif /* MODELS_MEMENTO_BOARDMEMENTO_H_ */
