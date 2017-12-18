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

void ActionView::visit(Controllers::MoveController &moveController) {
	this->moveView.interact(moveController);
}

void ActionView::visit(Controllers::FlipController &flipController) {
	this->flipView.interact(flipController);
}

void ActionView::visit(Controllers::UndoController &undoController) {
	undoController.execute();
}

void ActionView::visit(Controllers::RedoController &redoController) {
	redoController.execute();
}

} /* namespace Console */
} /* namespace Views */
