#include "NoobSolitarieView.h"

namespace Views {
namespace Console {

NoobSolitarieView::NoobSolitarieView() : startView(), gameView(), actionView(){

}

NoobSolitarieView::~NoobSolitarieView() {
}

void NoobSolitarieView::interact(Controllers::OperationController &operationController) {
	assert(&operationController);

	operationController.accept(*this);
}

void NoobSolitarieView::visit(Controllers::StartController &startController) {
	this->startView.interact(startController);
}

void NoobSolitarieView::visit(Controllers::InitialGameDecitionController &initialGameDecitionController) {
	this->gameView.interact(initialGameDecitionController);
}

void NoobSolitarieView::visit(Controllers::ActionController &actionController) {
	this->actionView.interact(actionController);
}

} /* namespace Console */
} /* namespace Views */
