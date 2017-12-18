#include "Board.h"
#include <iostream>

namespace Models {

Board::Board(int suitNumberMax, int cardsPerSuitMax, int tableausNumberMax, int stockVisibleCardsMax) :
		deck(suitNumberMax, cardsPerSuitMax), stock(stockVisibleCardsMax) {
	assert(0 < suitNumberMax);
	assert(0 < cardsPerSuitMax);

	this->suitNumberMax = suitNumberMax;
	this->cardsPerSuitMax = cardsPerSuitMax;
	this->tableausNumberMax = tableausNumberMax;
	this->tableau = new Tableau[this->tableausNumberMax]();
	int j;
	for (int i = 0; i < this->tableausNumberMax; i++) {
		for (j = 0; j <= i; j++) {
			this->tableau[i].add(this->deck.getRandomCard());
		}
		this->tableau[i].setHiddenCardsNumber(j - 1);
	}

	while (this->deck.isThereCardsToGive()) {
		this->stock.add(this->deck.getRandomCard());
	}
	this->stock.setHiddenCardsNumber(this->stock.getCardsNumber());

	this->foundation = new Foundation[suitNumberMax]();
}

Board::~Board() {
}

bool Board::canFlip(){
	return this->stock.canFlip();
}

void Board::flip(){
	return this->stock.flip();
}

int Board::getCardsPerSuitMax() {
	return this->cardsPerSuitMax;
}

int Board::getSuitNumberMax() {
	return this->suitNumberMax;
}

int Board::getTableausNumberMax() {
	return this->tableausNumberMax;
}

Deck& Board::getDeck() {
	return this->deck;
}

Tableau& Board::getTableau(int index) {
	assert(0 <= index && index < this->tableausNumberMax);

	return this->tableau[index];
}

Foundation& Board::getFoundation(int index) {
	assert(0 <= index && index < this->suitNumberMax);

	return this->foundation[index];
}

Stock& Board::getStock() {
	return this->stock;
}

int Board::getVisibleCardsNumberFromTableau(int index) {
	return this->tableau[index].getVisibleCardsNumber();
}

Memento::BoardMemento& Board::createMemento() {
	Memento::BoardMemento &result = *new Memento::BoardMemento(this->suitNumberMax, this->cardsPerSuitMax, this->tableausNumberMax, this->stock.createMemento());

	for (int i = 0; i < this->tableausNumberMax; i++) {
		result.addTableauMemento(this->tableau[i].createMemento());
	}
	for (int i = 0; i < this->suitNumberMax; i++) {
		result.addFoundationMemento(this->foundation[i].createMemento());
	}

	return result;
}

void Board::setMemento(Memento::BoardMemento &boardMemento) {
	this->suitNumberMax = boardMemento.getSuitNumberMax();
	this->cardsPerSuitMax = boardMemento.getCardsPerSuitMax();
	this->tableausNumberMax = boardMemento.getTableausNumberMax();

	int i = 0;
	for (auto it = boardMemento.getTableauMementosBegin(); it != boardMemento.getTableauMementosEnd(); ++it) {
		this->tableau[i++].setMemento(*it);
	}

	i = 0;
	for (auto it = boardMemento.getFoundationMementosBegin(); it != boardMemento.getFoundationMementosEnd(); ++it) {
		this->foundation[i++].setMemento(*it);
	}
	this->stock.setMemento(boardMemento.getStockMemento());
}

} /* namespace Models */
