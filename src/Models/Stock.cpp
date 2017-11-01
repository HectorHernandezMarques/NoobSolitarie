#include "Stock.h"

namespace Models {

Stock::Stock(int visibleCardsMax) :
		Stack() {
	this->visibleCardsMax = visibleCardsMax;
	this->hiddenCardsNumber = 0;
	this->visibleCardsNumber = 0;
}

Stock::Stock(Utils::Node<Cards::Card> &card, int visibleCardsMax) :
		Stack(card) {
	assert(&card);

	this->visibleCardsMax = visibleCardsMax;
	this->hiddenCardsNumber = this->getCardsNumber();
	this->visibleCardsNumber = 0;
}

Stock::~Stock() {
}

Utils::Node<Cards::Card>& Stock::remove(int index) {
	assert(0 <= index && index < this->getCardsNumber());

	this->visibleCardsNumber--;
	return this->stack.remove(index);
}

bool Stock::canFlip() {
	return this->getCardsNumber();
}

void Stock::flip() {
	assert(this->canFlip());

	if (this->hiddenCardsNumber) {
		this->visibleCardsNumber =
				(this->hiddenCardsNumber > this->visibleCardsMax) ? this->visibleCardsMax : this->hiddenCardsNumber;
		this->hiddenCardsNumber =
				(this->hiddenCardsNumber > this->visibleCardsMax) ? this->hiddenCardsNumber - this->visibleCardsMax : 0;
	} else {
		this->visibleCardsNumber = 0;
		this->hiddenCardsNumber = this->getCardsNumber();
	}
}

bool Stock::canRemove(Cards::Card &card) {
	assert(&card);

	int index = this->stack.getIndex(card);
	return (this->getCardsNumber() - this->hiddenCardsNumber - this->visibleCardsNumber) <= index
			&& index < (this->getCardsNumber() - this->hiddenCardsNumber);
}

Cards::Card& Stock::getLastCard() {
	assert(this->getCardsNumber());

	return this->stack.get(this->getCardsNumber() - this->hiddenCardsNumber - this->visibleCardsNumber);
}

int Stock::getVisibleCardsNumber() {
	return visibleCardsNumber;
}

int Stock::getHiddenCardsNumber() {
	return hiddenCardsNumber;
}

void Stock::setHiddenCardsNumber(int hiddenCardsNumber) {
	assert(0 <= hiddenCardsNumber && hiddenCardsNumber <= this->getCardsNumber());

	this->hiddenCardsNumber = hiddenCardsNumber;
}

} /* namespace Models */
