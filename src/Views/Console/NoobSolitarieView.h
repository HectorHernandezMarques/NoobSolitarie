#ifndef VIEWS_CONSOLE_NOOBSOLITARIEVIEW_H_
#define VIEWS_CONSOLE_NOOBSOLITARIEVIEW_H_

#include "../OperationControllerView.h"
#include "StartView.h"
#include "GameView.h"
#include "ActionView.h"
#include "../../Controllers/OperationControllerVisitor.h"

namespace Views {
namespace Console {

class NoobSolitarieView: public OperationControllerView, public Controllers::OperationControllerVisitor {
private:
	StartView startView;
	GameView gameView;
	ActionView actionView;

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
