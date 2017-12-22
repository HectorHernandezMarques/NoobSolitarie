#include "./InitialGameDecitionNameView.h"

namespace Views {
namespace Console {
namespace ModelsViews {


InitialGameDecitionNameView::InitialGameDecitionNameView(Controllers::InitialGameDecition initialGameDecition) : initialGameDecition(initialGameDecition) {
}

InitialGameDecitionNameView::~InitialGameDecitionNameView() {
}

void InitialGameDecitionNameView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	io.write(this->toString());
}

std::string InitialGameDecitionNameView::toString() {
	std::string initialGameDecition;
	switch (this->initialGameDecition) {
		case Controllers::InitialGameDecition::FLIP:
			initialGameDecition = "Flip";
			break;
		case Controllers::InitialGameDecition::MOVE:
			initialGameDecition = "Move";
			break;
		case Controllers::InitialGameDecition::REDO:
			initialGameDecition = "Redo";
			break;
		case Controllers::InitialGameDecition::UNDO:
			initialGameDecition = "Undo";
			break;
		default:
			initialGameDecition = "Unable Command";
		}

	return initialGameDecition;
}

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */
