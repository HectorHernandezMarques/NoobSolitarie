#ifndef CARDS_DECK_H_
#define CARDS_DECK_H_

#include <time.h>
#include <cstdlib>
#include "./Cards/Card.h"

namespace Models{

class Deck {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	Cards::Card **cards;
	int servedCardsNumber;
	bool *servedCards;

public:
	Deck(int suitNumberMax, int cardsPerSuitMax);
	virtual ~Deck() {
	}

	Cards::Card& getRandomCard();
	void resetDeck();
	bool isThereCardsToGive();

	Cards::Card& getCard(int suit, int number);
	Cards::Card& getCard(int absoluteIndex);
};

} /* namespace Models */

#endif /* CARDS_DECK_H_ */
