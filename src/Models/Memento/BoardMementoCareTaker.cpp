#include "./BoardMementoCareTaker.h"

namespace Models {
namespace Memento {

BoardMementoCareTaker::BoardMementoCareTaker() : boardMementos(), currentMemento(this->boardMementos.end()) {

}

BoardMementoCareTaker::~BoardMementoCareTaker() {

}

void BoardMementoCareTaker::addMemento(BoardMemento &boardMemento) {
	std::list<BoardMemento>::iterator insertedElement = this->boardMementos.insert(this->currentMemento, boardMemento);
	this->boardMementos.erase(std::next(insertedElement), this->boardMementos.end());
	this->currentMemento = this->boardMementos.end();
}

bool BoardMementoCareTaker::hasPreviousMemento() {
	return this->currentMemento != std::next(this->boardMementos.begin());
}

bool BoardMementoCareTaker::hasNextMemento() {
	return this->currentMemento != this->boardMementos.end();
}

BoardMemento& BoardMementoCareTaker::getPreviousMemento() {
	assert(this->hasPreviousMemento());

	return *std::prev(std::prev(this->currentMemento));
}

BoardMemento& BoardMementoCareTaker::getNextMemento() {
	assert(this->hasNextMemento());

	return *this->currentMemento;
}

void BoardMementoCareTaker::setPreviousMemento() {
	assert(this->hasPreviousMemento());

	this->currentMemento--;
}

void BoardMementoCareTaker::setNextMemento() {
	assert(this->hasNextMemento());

	this->currentMemento++;
}

} /* namespace Memento */
} /* namespace Models */
