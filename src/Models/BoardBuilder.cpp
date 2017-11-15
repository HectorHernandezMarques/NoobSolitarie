#include "BoardBuilder.h"
#include <iostream>
namespace Models {

BoardBuilder::BoardBuilder() :
		suitNumberMax(SUIT_NUMBER_MAX), cardsPerSuitMax(CARDS_PER_SUIT_MAX), tableausNumberMax(TABLEAUS_NUMBER_MAX), stockVisibleCardsMax(
				STOCK_VISIBLE_CARDS_MAX) {
}

BoardBuilder::~BoardBuilder() {
}

Board& BoardBuilder::getBoard(){
	return *(new Board(suitNumberMax, cardsPerSuitMax, tableausNumberMax, stockVisibleCardsMax));
}

} /* namespace Models */
