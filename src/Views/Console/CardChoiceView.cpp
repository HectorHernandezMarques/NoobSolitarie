#include "CardChoiceView.h"

namespace Views {
namespace Console {

CardChoiceView::CardChoiceView(Controllers::CardChoice &cardChoice) :
		cardChoice(cardChoice) {
	assert(&cardChoice);
}

CardChoiceView::~CardChoiceView() {
}

void CardChoiceView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	if (this->cardChoice.getCards().getItemsNumber() > 0) {
		for (int i = 0; i < this->cardChoice.getCards().getItemsNumber(); i++) {
			(new CardView(this->cardChoice.getCards().get(i)))->write();
		}
	} else {
		io.write("|o|");
	}
	io.writeln("");
}

} /* namespace Console */
} /* namespace Views */
