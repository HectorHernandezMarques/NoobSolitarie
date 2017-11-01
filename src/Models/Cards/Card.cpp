#include "Card.h"

namespace Models {
namespace Cards {

Card::Card() :
		suit(0), number(0, 0) {
}

Card::Card(int suit, int number, int maxNumber) :
		suit(suit), number(number, maxNumber) {
	assert(suit >= 0);
	assert(number >= 0);
	assert(maxNumber >= 0);
}

Card::~Card() {
}

bool Card::isFirstNumber() {
	return this->number.isFirst();
}

bool Card::isLastNumber() {
	return this->number.isLast();
}

bool Card::isNextNumberOf(Card &card) {
	assert(&card);

	return this->number.isNextOf(card.number);
}

bool Card::isSameSuitThan(Card &card) {
	assert(&card);

	return this->suit == card.suit;
}

bool Card::isSameSuitParityOf(Card &card) {
	assert(&card);

	return this->suit.isSameParityOf(card.suit);
}

bool Card::operator==(Card &card) {
	assert(&card);

	return this->number == card.number && this->suit == card.suit;
}

bool Card::operator!=(Card &card) {
	assert(&card);

	return !(*this == card);
}

} /* namespace Cards */
} /* namespace Models */
