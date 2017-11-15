#ifndef MODELS_BOARDBUILDER_H_
#define MODELS_BOARDBUILDER_H_

#include "Board.h"
#include "Definitions.h"

namespace Models {

class BoardBuilder {
private:
	int suitNumberMax;
	int cardsPerSuitMax;
	int tableausNumberMax;
	int stockVisibleCardsMax;
public:
	BoardBuilder();
	virtual ~BoardBuilder();

	Board& getBoard();
};

} /* namespace Models */

#endif /* MODELS_BOARDBUILDER_H_ */
