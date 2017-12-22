#include "./NumberView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

NumberView::NumberView(Models::Cards::Number &number) :
		number(number) {
	assert(&number);
}

NumberView::~NumberView() {
}

void NumberView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	switch (this->number.getNumber()) {
	case 0:
		io.write("A");
		break;
	case 10:
		io.write("J");
		break;
	case 11:
		io.write("Q");
		break;
	case 12:
		io.write("K");
		break;
	default:
		io.write(std::to_string(this->number.getNumber() + 1));
	}
}

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */
