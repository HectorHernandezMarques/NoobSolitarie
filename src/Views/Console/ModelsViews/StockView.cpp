#include "./StockView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

StockView::StockView(Models::Stock &stock) :
		stock(stock) {
	assert(&stock);
}

StockView::~StockView() {
}

void StockView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	if (this->stock.getCardsNumber()) {
		if (this->stock.getHiddenCardsNumber()) {
			io.write("|X|  ");
		} else {
			io.write("|o|  ");
		}
		if(this->stock.getVisibleCardsNumber()){
			Utils::Stack<Models::Cards::Card> &visibleCards = this->stock.getVisibleCards();
			for (int i = 0; i < this->stock.getVisibleCardsNumber(); i++) {
				io.write("|");
				(new CardView(visibleCards.get(i)))->write();
				io.write("|  ");
			}
		}
		for (int i = 0; i < (this->stock.getVisibleCardsMax() - this->stock.getVisibleCardsNumber()); i++) {
			io.write("|o|  ");
		}
	} else {
		io.write("|o|   |o|  |o|  |o|  ");
	}
	io.write("<<");
}

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */
