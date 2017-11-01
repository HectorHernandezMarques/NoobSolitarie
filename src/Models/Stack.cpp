#include "Stack.h"

namespace Models {

Stack::Stack() :
		stack() {
}

Stack::Stack(Utils::Node<Cards::Card> &card) :
		stack(card) {
}

Stack::~Stack() {
}

void Stack::add(Utils::Node<Cards::Card> &card) {
	assert(&card);

	this->stack.add(card);
}

Utils::Node<Cards::Card>& Stack::remove(Cards::Card &card) {
	assert(&card);
	assert(this->canRemove(card));

	return this->remove(this->stack.getIndex(card));
}

Cards::Card& Stack::getCard(int index) {
	assert(index >= 0);
	assert(index < this->stack.getItemsNumber());

	return stack.get(index);
}

Cards::Card& Stack::getLastCard() {
	assert(this->stack.getItemsNumber());

	return this->getCard(this->getCardsNumber() - 1);
}

int Stack::getCardsNumber() {
	return this->stack.getItemsNumber();
}

} /* namespace Models */
