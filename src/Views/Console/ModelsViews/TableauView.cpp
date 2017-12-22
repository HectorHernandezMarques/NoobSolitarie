#include "./TableauView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

TableauView::TableauView(Models::Tableau &tableau) :
		tableau(tableau) {
	assert(&tableau);
}

TableauView::~TableauView() {
}

void TableauView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	if (this->tableau.getCardsNumber() > 0) {
		io.write("|");
		for (int i = 0; i < this->tableau.getHiddenCardsNumber(); i++) {
			//(new CardView(this->tableau.getCard(i)))->write();
			io.write("X");
			io.write("|");
		}
		if (this->tableau.getVisibleCardsNumber()) {
			Utils::Stack<Models::Cards::Card> &visibleCards = this->tableau.getVisibleCards();
			for (int i = 0; i < this->tableau.getVisibleCardsNumber(); i++) {
				(new CardView(visibleCards.get(i)))->write();
			}
		}
	} else {
		io.write("|o|");
	}
}

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */
