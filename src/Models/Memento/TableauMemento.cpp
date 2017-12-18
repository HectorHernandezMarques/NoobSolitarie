#include "./TableauMemento.h"

namespace Models {
namespace Memento {

TableauMemento::TableauMemento(int hiddenCardsNumber, Utils::Stack<Cards::Card> &cards) :
		hiddenCardsNumber(hiddenCardsNumber), cards(cards){
}

TableauMemento::TableauMemento(const TableauMemento &tableauMemento) :
	hiddenCardsNumber(tableauMemento.hiddenCardsNumber), cards(tableauMemento.cards) {
}

TableauMemento::~TableauMemento() {

}

int TableauMemento::getHiddenCardsNumber() {
	return this->hiddenCardsNumber;
}

Utils::Stack<Cards::Card> TableauMemento::getCards() {
	return this->cards;
}


} /* namespace Tableau */
} /* namespace Models */
