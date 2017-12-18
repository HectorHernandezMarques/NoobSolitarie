#include "./BoardMemento.h"
#include <iostream>

namespace Models {
namespace Memento {

BoardMemento::BoardMemento(int suitNumberMax, int cardsPerSuitMax, int tableausNumberMax, Memento::StockMemento &stockMemento) :
		suitNumberMax(suitNumberMax), cardsPerSuitMax(cardsPerSuitMax), tableausNumberMax(tableausNumberMax), stockMemento(stockMemento) {
}

BoardMemento::BoardMemento(const BoardMemento &boardMemento) :
	suitNumberMax(boardMemento.suitNumberMax), cardsPerSuitMax(boardMemento.cardsPerSuitMax), tableausNumberMax(boardMemento.tableausNumberMax), stockMemento(boardMemento.stockMemento),
	tableauMementos(boardMemento.tableauMementos), foundationMementos(boardMemento.foundationMementos){
}

BoardMemento::~BoardMemento() {

}

void BoardMemento::addTableauMemento(TableauMemento &tableauMemento) {
	this->tableauMementos.emplace_back(tableauMemento);
}

void BoardMemento::addFoundationMemento(FoundationMemento &foundationMemento) {
	this->foundationMementos.emplace_back(foundationMemento);
}

int BoardMemento::getSuitNumberMax() {
	return this->suitNumberMax;
}

int BoardMemento::getCardsPerSuitMax() {
	return this->cardsPerSuitMax;
}

int BoardMemento::getTableausNumberMax() {
	return this->tableausNumberMax;
}

std::list<TableauMemento>::iterator BoardMemento::getTableauMementosBegin() {
	return this->tableauMementos.begin();
}

std::list<TableauMemento>::iterator BoardMemento::getTableauMementosEnd() {
	return this->tableauMementos.end();
}

std::list<FoundationMemento>::iterator BoardMemento::getFoundationMementosBegin() {
	return this->foundationMementos.begin();
}

std::list<FoundationMemento>::iterator BoardMemento::getFoundationMementosEnd() {
	return this->foundationMementos.end();
}

StockMemento& BoardMemento::getStockMemento() {
	return this->stockMemento;
}

} /* namespace Memento */
} /* namespace Models */
