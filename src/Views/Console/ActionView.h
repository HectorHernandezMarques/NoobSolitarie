#ifndef VIEWS_CONSOLE_ACTIONVIEW_H_
#define VIEWS_CONSOLE_ACTIONVIEW_H_

#include "./FlipView.h"
#include "./MoveView.h"
#include "../../Controllers/ActionControllerVisitor.h"

namespace Views {
namespace Console {

class ActionView : public Controllers::ActionControllerVisitor{
private:
	FlipView flipView;
	MoveView moveView;

public:
	ActionView();
	virtual ~ActionView();

	void interact(Controllers::ActionController &actionController);
	void visit(Controllers::MoveController &moveController);
	void visit(Controllers::FlipController &flipController);
	void visit(Controllers::UndoController &undoController);
	void visit(Controllers::RedoController &redoController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_ACTIONVIEW_H_ */
