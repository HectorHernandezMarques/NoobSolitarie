#include "ActionView.h"

namespace Views {
namespace Console {

ActionView::ActionView() :
		flipView() {
}

ActionView::~ActionView() {
}

void ActionView::interact(Controllers::ActionController &actionController) {
	assert(&actionController);

	actionController.accept(*this);
}

void ActionView::visit(Controllers::FlipController &flipController) {
	this->flipView.interact(flipController);
}

void ActionView::visit(Controllers::MoveController &moveController) {
	this->moveView.interact(moveController);
}

} /* namespace Console */
} /* namespace Views */
