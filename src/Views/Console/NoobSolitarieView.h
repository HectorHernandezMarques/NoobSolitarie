#ifndef VIEWS_CONSOLE_NOOBSOLITARIEVIEW_H_
#define VIEWS_CONSOLE_NOOBSOLITARIEVIEW_H_

#include "../../Controllers/OperationControllerVisitor.h"
#include "../OperationControllerView.h"
#include "./ControllersViews/StartView.h"
#include "./ControllersViews/ActionView.h"
#include "./ControllersViews/InitialGameDecitionView.h"

namespace Views {
namespace Console {

class NoobSolitarieView: public OperationControllerView, public Controllers::OperationControllerVisitor {
private:
	ControllersViews::StartView startView;
	ControllersViews::InitialGameDecitionView gameView;
	ControllersViews::ActionView actionView;

public:
	NoobSolitarieView();
	virtual ~NoobSolitarieView();

	void interact(Controllers::OperationController &operationController);
	void visit(Controllers::StartController &startController);
	void visit(Controllers::InitialGameDecitionController &initialGameDecitionController);
	void visit(Controllers::ActionController &actionController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_NOOBSOLITARIEVIEW_H_ */
