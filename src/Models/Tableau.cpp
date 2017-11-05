#include "Tableau.h"

namespace Models{

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

bool Tableau::canAdd(Cards::Card &card) {
	assert(&card);

	bool result = false;
	if (this->getCardsNumber()) {
		result = !this->stack.getLast().isSameSuitParityOf(card)
				&& this->stack.getLast().isNextNumberOf(card);
	} else {
		result = card.isLastNumber();
	}
	return result;
}

bool Tableau::canRemove(Cards::Card &card) {
	assert(&card);

	int index = this->stack.getIndex(card);
	return this->hiddenCardsNumber <= index && index < this->getCardsNumber();
}

Cards::Card& Tableau::getRelativeCard(int relativeIndex) {
	assert(0 < relativeIndex && relativeIndex <= this->getCardsNumber());

	int absoluteIndex = this->getCardsNumber() - relativeIndex;
	return this->getCard(absoluteIndex);
}

int Tableau::getHiddenCardsNumber() {
	return this->hiddenCardsNumber;
}

void Tableau::setHiddenCardsNumber(int hiddenCardsNumber) {
	assert(0 <= hiddenCardsNumber && hiddenCardsNumber <= this->getCardsNumber());

	this->hiddenCardsNumber = hiddenCardsNumber;
}

} /* namespace Models */
