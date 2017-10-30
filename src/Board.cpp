/*
 * Board.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: eherhes
 */

#include "Board.h"

Board::Board(int suitNumberMax, int cardsPerSuitMax, int tableausNumberMax, int stockVisibleCardsMax) :
		deck(suitNumberMax, cardsPerSuitMax), stock(stockVisibleCardsMax) {
	assert(suitNumberMax > 0);
	assert(cardsPerSuitMax > 0);

	this->suitNumberMax = suitNumberMax;
	this->cardsPerSuitMax = cardsPerSuitMax;
	this->tableausNumberMax = tableausNumberMax;
	this->tableau = new Tableau[this->tableausNumberMax]();
	int j;
	for (int i = 0; i < this->tableausNumberMax; i++) {
		for (j = 0; j <= i; j++) {
			this->tableau[i].add(new Utils::Node<Cards::Card>(this->deck.getRandomCard(), nullptr, nullptr));
		}
		this->tableau[i].setHiddenCardsNumber(j - 1);
	}

	while (this->deck.isThereCardsToGive()) {
		this->stock.add(new Utils::Node<Cards::Card>(this->deck.getRandomCard(), nullptr, nullptr));
	}
	this->stock.setHiddenCardsNumber(this->stock.getCardsNumber());

	this->foundation = new Foundation[suitNumberMax]();
}

Board::~Board() {
}

std::string Board::toString() {
	std::string result = "\n";
	for (int i = 0; i < this->suitNumberMax; i++) {
		result += this->foundation[i].toString() + "  ";
	}
	result += "\n\n";
	for (int i = 0; i < this->tableausNumberMax; i++) {
		result += std::to_string(i + 1) + " - " + this->tableau[i].toString() + "\n";
	}
	result += "\n\n";
	result += "     " + this->stock.toString() + "\n\n";
	return result;
}
