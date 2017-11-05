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

bool Foundation::canAdd(Cards::Card &card) {
	assert(&card);

	bool result = false;
	if (this->getCardsNumber() == 0) {
		result = card.isFirstNumber();
	} else {
		result = card.isSameSuitThan(this->getLastCard()) && card.isNextNumberOf(this->getLastCard());
	}
	return result;
}

bool Foundation::canRemove(Cards::Card &card) {
	assert(&card);

	int index = this->stack.getIndex(card);
	return index == (this->getCardsNumber() - 1);
}

Cards::Card& Foundation::getRelativeCard() {
	return this->getCard(this->getCardsNumber() - 1);
}

} /* namespace Models */
