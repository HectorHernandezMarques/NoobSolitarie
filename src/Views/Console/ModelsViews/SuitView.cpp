#include "./SuitView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

SuitView::SuitView(Models::Cards::Suit &suit) :
		suit(suit) {
}

SuitView::~SuitView() {
}

void SuitView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	std::string suit;
	switch (this->suit.getSuit()) {
	case 0:
		suit = (char) 3;
		break;
	case 1:
		suit = (char) 5;
		break;
	case 2:
		suit = (char) 4;
		break;
	case 3:
		suit = (char) 6;
		break;
	default:
		suit = (char) 1;
	}
	io.write(suit);
}

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */
