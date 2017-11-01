#ifndef CARDS_CARD_H_
#define CARDS_CARD_H_

#include "Suit.h"
#include "Number.h"

namespace Models {
namespace Cards {

class Card {
private:
	Suit suit;
	Number number;

public:
	Card();
	Card(int suit, int number, int maxNumber);
	virtual ~Card();

	bool isFirstNumber();
	bool isLastNumber();
	bool isNextNumberOf(Card &card);
	bool isSameSuitThan(Card &card);
	bool isSameSuitParityOf(Card &card);
	bool operator==(Card &card);
	bool operator!=(Card &card);

	Number& getNumber(){
		return this->number;
	}
	Suit& getSuit(){
		return this->suit;
	}
};

} /* namespace Cards */
} /* namespace Models */

#endif /* CARDS_CARD_H_ */
