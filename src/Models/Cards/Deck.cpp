#include "Deck.h"

namespace Models{
namespace Cards {

Deck::Deck(int suitNumberMax, int cardsPerSuitMax) {
	assert(0 < suitNumberMax);
	assert(0 < cardsPerSuitMax);

	std::srand(time(nullptr));
	this->suitNumberMax = suitNumberMax;
	this->cardsPerSuitMax = cardsPerSuitMax;
	this->cards = new Card*[this->suitNumberMax];
	for (int i = 0; i < this->suitNumberMax; ++i) {
		this->cards[i] = new Card[this->cardsPerSuitMax];
	}
	for (int i = 0; i < this->suitNumberMax; i++) {
		for (int j = 0; j < this->cardsPerSuitMax; j++) {
			this->cards[i][j] = *new Card(i, j, this->cardsPerSuitMax);
		}
	}
	this->servedCards = new bool[this->suitNumberMax * this->cardsPerSuitMax];
	this->resetDeck();
}

Card& Deck::getRandomCard() {
	assert(this->isThereCardsToGive());

	int nextCard = rand() % (this->suitNumberMax * this->cardsPerSuitMax);
	while (this->servedCards[nextCard]) {
		nextCard = (nextCard + 1) % (this->suitNumberMax * this->cardsPerSuitMax);
	}
	this->servedCardsNumber++;
	this->servedCards[nextCard] = true;
	return this->getCard(nextCard);
}

void Deck::resetDeck() {
	this->servedCardsNumber = 0;
	for (int i = 0; i < (this->suitNumberMax * this->cardsPerSuitMax); i++) {
		this->servedCards[i] = false;
	}
}

bool Deck::isThereCardsToGive() {
	return (this->suitNumberMax * this->cardsPerSuitMax) > this->servedCardsNumber;
}

Card& Deck::getCard(int suit, int number) {
	assert(0 <= suit && suit < this->suitNumberMax);
	assert(0 <= number && number < this->cardsPerSuitMax);

	return cards[suit][number];
}

Card& Deck::getCard(int absoluteIndex) {
	assert(0 <= absoluteIndex && absoluteIndex < (this->suitNumberMax * this->cardsPerSuitMax));

	return cards[absoluteIndex / cardsPerSuitMax][absoluteIndex % cardsPerSuitMax];
}

} /* namespace Cards */
} /* namespace Models */
