#include "Suit.h"

namespace Models{
namespace Cards {

Suit::Suit(int suit) {
	assert(suit >= 0);

	this->suit = suit;
}

Suit::~Suit() {
}

bool Suit::isSameParityOf(Suit &suit) {
	assert(&suit);

	return (this->suit % 2) == (suit.suit % 2);
}

bool Suit::operator==(Suit &suit) {
	assert(&suit);

	return this->suit == suit.suit;
}

int Suit::getSuit() {
	return this->suit;
}

} /* namespace Cards */
} /* namespace Models */
