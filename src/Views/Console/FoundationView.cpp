#include "FoundationView.h"

namespace Views {
namespace Console {

FoundationView::FoundationView(Models::Foundation &foundation) :
		foundation(foundation) {
}

FoundationView::~FoundationView() {
}

void FoundationView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	if (this->foundation.getVisibleCardsNumber()) {
		Utils::Stack<Models::Cards::Card> &visibleCards = this->foundation.getVisibleCards();
		for (int i = 0; i < this->foundation.getVisibleCardsNumber(); i++) {
			io.write("|");
			(new CardView(visibleCards.get(i)))->write();
			io.write("|  ");
		}
	} else {
		io.write("|o|");
	}
}

} /* namespace Console */
} /* namespace Views */
