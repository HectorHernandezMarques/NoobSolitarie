#include "./StockMemento.h"

namespace Models {
namespace Memento {

StockMemento::StockMemento(int visibleCardsMax, int hiddenCardsNumber, int visibleCardsNumber, Utils::Stack<Cards::Card> &cards) :
		visibleCardsMax(visibleCardsMax), hiddenCardsNumber(hiddenCardsNumber), visibleCardsNumber(visibleCardsNumber), cards(cards) {
}

StockMemento::StockMemento(const StockMemento &stockMemento) :
	visibleCardsMax(stockMemento.visibleCardsMax), hiddenCardsNumber(stockMemento.hiddenCardsNumber), visibleCardsNumber(stockMemento.visibleCardsNumber), cards(stockMemento.cards) {
}

StockMemento::~StockMemento() {

}

int StockMemento::getVisibleCardsMax() {
	return this->visibleCardsMax;
}

int StockMemento::getHiddenCardsNumber() {
	return this->hiddenCardsNumber;
}

int StockMemento::getVisibleCardsNumber() {
	return this->visibleCardsNumber;
}

Utils::Stack<Cards::Card> StockMemento::getCards() {
	return this->cards;
}

} /* namespace Memento */
} /* namespace Models */
