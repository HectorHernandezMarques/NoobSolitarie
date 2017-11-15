#include "Stack.h"

namespace Models {

Stack::Stack() :
		stack() {
}

Stack::Stack(Utils::Stack<Cards::Card> &card) :
		stack(card) {
}

Stack::~Stack() {
}

void Stack::add(Cards::Card &card) {
	assert(&card);

	Utils::Stack<Cards::Card> stack(card);
	this->stack.add(stack);
}

void Stack::add(Utils::Stack<Cards::Card> &card) {
	assert(&card);

	this->stack.add(card);
}

Utils::Stack<Cards::Card>& Stack::remove(Cards::Card &card) {
	assert(&card);
	assert(this->canRemove(card));

	return this->remove(this->stack.getIndex(card));
}

Cards::Card& Stack::getCard(int index) {
	assert(0 <= index);
	assert(index < this->stack.getItemsNumber());

	return stack.get(index);
}

Cards::Card& Stack::getLastCard() {
	assert(this->stack.getItemsNumber());

	return this->getCard(this->getCardsNumber() - 1);
}

Utils::Stack<Cards::Card>& Stack::getUntilEnd(int index){
	assert(this->stack.getItemsNumber());
	assert(index < this->stack.getItemsNumber());

	return this->stack.getUntilEnd(index);
}

int Stack::getCardsNumber() {
	return this->stack.getItemsNumber();
}

} /* namespace Models */
