#include "Foundation.h"

namespace Models {

Foundation::Foundation() :
		StackAddable() {
}

Foundation::Foundation(Utils::Node<Cards::Card> &card) :
		StackAddable(card) {
}

Foundation::~Foundation() {
}

Utils::Node<Cards::Card>& Foundation::remove(int index) {
	assert(0 <= index < this->getCardsNumber());

	return this->stack.remove(index);
}

bool Foundation::canAdd(Cards::Card &card) {
	assert(&card);

	bool result = false;
	if (this->getCardsNumber() == 0) {
		result = card.isFirstNumber();
	} else {
		result = card.isSameSuitThan(this->stack.getLast()) && card.isNextNumberOf(this->stack.getLast());
	}
	return result;
}

bool Foundation::canRemove(Cards::Card &card) {
	assert(&card);

	int index = this->stack.getIndex(card);
	return index == (this->getCardsNumber() - 1);
}

Cards::Card& Foundation::getCard() {
	return stack.get(this->getCardsNumber() - 1);
}

} /* namespace Models */
