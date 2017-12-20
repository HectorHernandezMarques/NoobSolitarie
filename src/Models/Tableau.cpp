#include "Tableau.h"

namespace Models {

Tableau::Tableau() :
		StackAddable() {
	this->hiddenCardsNumber = 0;
}

Tableau::Tableau(Utils::Stack<Cards::Card> &card) :
		StackAddable(card) {
	assert(&card);

	this->hiddenCardsNumber = this->getCardsNumber() - 1;
}

Tableau::~Tableau() {
}

Utils::Stack<Cards::Card>& Tableau::remove(int index) {
	assert(0 <= index && index < this->getCardsNumber());

	this->hiddenCardsNumber =
			(index == this->hiddenCardsNumber && this->hiddenCardsNumber > 0) ?
					this->hiddenCardsNumber - 1 : this->hiddenCardsNumber;

	return this->stack.removeUntilEnd(index);
}

bool Tableau::canAdd(Utils::Stack<Cards::Card> &cards) {
	assert(&cards);

	bool result = false;
	if (this->getCardsNumber()) {
		result = !this->stack.getLast().isSameSuitParityOf(cards.get(0)) && this->stack.getLast().isNextNumberOf(cards.get(0));
	} else {
		result = cards.get(0).isLastNumber();
	}
	return result;
}

bool Tableau::canRemove(Cards::Card &card) {
	assert(&card);

	int index = this->stack.getIndex(card);
	return this->hiddenCardsNumber <= index && index < this->getCardsNumber();
}

bool Tableau::canRemoveRelativeCards(int relativeIndex) {
	assert(0 < relativeIndex);

	bool result = false;
	if (0 < relativeIndex && relativeIndex <= (this->getCardsNumber() - this->hiddenCardsNumber)) {
		result = this->canRemove(this->getRelativeCards(relativeIndex).get(0));
	}

	return result;
}

void Tableau::setHiddenCardsNumber(int hiddenCardsNumber) {
	assert(0 <= hiddenCardsNumber && hiddenCardsNumber <= this->getCardsNumber());

	this->hiddenCardsNumber = hiddenCardsNumber;
}

Utils::Stack<Cards::Card>& Tableau::getRelativeCards(int relativeIndex) {
	assert(0 < relativeIndex && relativeIndex <= this->getCardsNumber());

	int absoluteIndex = this->getCardsNumber() - relativeIndex;
	return this->getUntilEnd(absoluteIndex);
}

Utils::Stack<Cards::Card>& Tableau::getVisibleCards(){
	assert(this->getCardsNumber());

	return this->getUntilEnd(this->hiddenCardsNumber);
}

int Tableau::getHiddenCardsNumber() {
	return this->hiddenCardsNumber;
}

int Tableau::getVisibleCardsNumber() {
	return this->getCardsNumber() - this->hiddenCardsNumber;
}

Memento::TableauMemento& Tableau::createMemento() {
	return *new Memento::TableauMemento(this->hiddenCardsNumber, this->stack);
}

void Tableau::setMemento(Memento::TableauMemento &tableauMemento) {
	this->hiddenCardsNumber = tableauMemento.getHiddenCardsNumber();
	this->stack = tableauMemento.getCards();
}

} /* namespace Models */
