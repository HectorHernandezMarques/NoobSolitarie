#ifndef CARDS_DECK_H_
#define CARDS_DECK_H_

#include <time.h>
#include "Card.h"

namespace Models{
namespace Cards {

class Deck {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	Card **cards;
	int servedCardsNumber;
	bool *servedCards;

public:
	Deck(int suitNumberMax, int cardsPerSuitMax);
	virtual ~Deck() {
	}

	Card& getRandomCard();
	void resetDeck();
	bool isThereCardsToGive();

	Card& getCard(int suit, int number);
	Card& getCard(int absoluteIndex);
};

} /* namespace Cards */
} /* namespace Models */

#endif /* CARDS_DECK_H_ */
