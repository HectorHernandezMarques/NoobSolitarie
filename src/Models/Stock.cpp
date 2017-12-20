#include "Stock.h"

namespace Models {

Stock::Stock(int visibleCardsMax) :
		Stack() {
	this->visibleCardsMax = visibleCardsMax;
	this->hiddenCardsNumber = 0;
	this->visibleCardsNumber = 0;
}

Stock::Stock(Utils::Stack<Cards::Card> &card, int visibleCardsMax) :
		Stack(card) {
	assert(&card);

	this->visibleCardsMax = visibleCardsMax;
	this->hiddenCardsNumber = this->getCardsNumber();
	this->visibleCardsNumber = 0;
}

Stock::~Stock() {
}

Utils::Stack<Cards::Card>& Stock::remove(int index) {
	assert(0 <= index && index < this->getCardsNumber());

	if ((this->getCardsNumber() - this->getHiddenCardsNumber()) > 1) {
		if(this->visibleCardsNumber > 1){
			this->visibleCardsNumber--;
		}
	} else {
		this->visibleCardsNumber = 0;
	}
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
	return index == (this->getCardsNumber() - this->hiddenCardsNumber - 1);
}

bool Stock::canRemoveRelativeCards() {
	bool result = false;
	if(this->getVisibleCardsNumber()){
		result = this->canRemove(this->getRelativeCards().get(0));
	}
	return result;
}

Utils::Stack<Cards::Card>& Stock::getRelativeCards() {
	assert(this->getCardsNumber());

	return *new Utils::Stack<Cards::Card>(this->stack.get(this->getCardsNumber() - this->hiddenCardsNumber - 1));
}

Utils::Stack<Cards::Card>& Stock::getVisibleCards() {
	assert(this->getCardsNumber());
	assert(this->getVisibleCardsNumber());

	Utils::Stack<Cards::Card> *result = new Utils::Stack<Cards::Card>;
	for(int i = 0; i < this->getVisibleCardsNumber(); i++){
		result->add(this->getCard(this->getCardsNumber() - this->getHiddenCardsNumber() - this->getVisibleCardsNumber() + i));
	}
	return *result;
}

int Stock::getVisibleCardsMax() {
	return this->visibleCardsMax;
}

int Stock::getHiddenCardsNumber() {
	return this->hiddenCardsNumber;
}

int Stock::getVisibleCardsNumber() {
	return this->visibleCardsNumber;
}

Memento::StockMemento& Stock::createMemento() {
	return *new Memento::StockMemento(this->visibleCardsMax,this->hiddenCardsNumber, this->visibleCardsNumber, this->stack);
}

void Stock::setHiddenCardsNumber(int hiddenCardsNumber) {
	assert(0 <= hiddenCardsNumber && hiddenCardsNumber <= this->getCardsNumber());

	this->hiddenCardsNumber = hiddenCardsNumber;
}

void Stock::setMemento(Memento::StockMemento &stockMemento) {
	this->visibleCardsMax = stockMemento.getVisibleCardsMax();
	this->hiddenCardsNumber = stockMemento.getHiddenCardsNumber();
	this->visibleCardsNumber = stockMemento.getVisibleCardsNumber();
	this->stack = stockMemento.getCards();
}

} /* namespace Models */
