#include "Foundation.h"

namespace Models {

Foundation::Foundation() :
		StackAddable() {
}

Foundation::Foundation(Utils::Stack<Cards::Card> &card) :
		StackAddable(card) {
}

Foundation::~Foundation() {
}

Utils::Stack<Cards::Card>& Foundation::remove(int index) {
	assert(0 <= index && index < this->getCardsNumber());

	return this->stack.remove(index);
}

bool Foundation::canAdd(Utils::Stack<Cards::Card> &cards) {
	assert(&cards);
	assert(cards.getItemsNumber() > 0);

	bool result = false;
	if (cards.getItemsNumber() == 1) {
		if (this->getCardsNumber() == 0) {
			result = cards.get(0).isFirstNumber();
		} else {
			result = cards.get(0).isSameSuitThan(this->getLastCard()) && cards.get(0).isNextNumberOf(this->getLastCard());
		}
	}
	return result;
}

bool Foundation::canRemove(Cards::Card &card) {
	assert(&card);

	int index = this->stack.getIndex(card);
	return index == (this->getCardsNumber() - 1);
}

bool Foundation::canRemoveRelativeCards() {
	bool result = false;
	if (this->getCardsNumber()) {
		result = this->canRemove(this->getRelativeCards().get(0));
	}
	return result;
}

Utils::Stack<Cards::Card>& Foundation::getRelativeCards() {
	assert(this->getCardsNumber());

	return *new Utils::Stack<Cards::Card>(this->getLastCard());
}

Utils::Stack<Cards::Card>& Foundation::getVisibleCards() {
	assert(this->getCardsNumber());

	return this->getUntilEnd(this->getCardsNumber() - 1);
}

int Foundation::getVisibleCardsNumber() {
	return this->getCardsNumber()?1:0;
}

Memento::FoundationMemento& Foundation::createMemento() {
	return *new Memento::FoundationMemento(this->stack);
}

void Foundation::setMemento(Memento::FoundationMemento &foundationMemento) {
	this->stack = foundationMemento.getCards();
}

} /* namespace Models */
