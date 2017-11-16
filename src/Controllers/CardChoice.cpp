#include "CardChoice.h"

namespace Controllers {

CardChoice::CardChoice(Models::Stack *stack, Utils::Stack<Models::Cards::Card> &cards) : stack(stack), cards(cards){
}

CardChoice::~CardChoice() {
}

Utils::Stack<Models::Cards::Card>& CardChoice::getCards() {
	return this->cards;
}

Models::Stack& CardChoice::getStack() {
	return *this->stack;
}

bool CardChoice::canAddInStack(Models::StackAddable &stackAddable){
	return stackAddable.canAdd(this->cards);
}

void CardChoice::removeCard() {
	this->stack->remove(this->cards.get(0));
}

} /* namespace Controllers */
