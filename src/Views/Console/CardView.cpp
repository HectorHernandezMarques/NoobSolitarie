#include "CardView.h"

namespace Views {
namespace Console {

CardView::CardView(Models::Cards::Card &card) : card(card){
	assert(&card);
}

CardView::~CardView() {
}

void CardView::write() {
	(new SuitView(this->card.getSuit()))->write();
	(new NumberView(this->card.getNumber()))->write();
}

} /* namespace Console */
} /* namespace Views */
