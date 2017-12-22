#include "./CardView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

CardView::CardView(Models::Cards::Card &card) : card(card){
	assert(&card);
}

CardView::~CardView() {
}

void CardView::write() {
	(new SuitView(this->card.getSuit()))->write();
	(new NumberView(this->card.getNumber()))->write();
}

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */
