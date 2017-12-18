#include "./FoundationMemento.h"

namespace Models {
namespace Memento {

FoundationMemento::FoundationMemento(Utils::Stack<Cards::Card> &cards) :
		cards(cards) {
}

FoundationMemento::FoundationMemento(const FoundationMemento &foundationMemento) :
	cards(foundationMemento.cards) {
}

FoundationMemento::~FoundationMemento() {

}

Utils::Stack<Cards::Card> FoundationMemento::getCards() {
	return this->cards;
}

} /* namespace Memento */
} /* namespace Models */
