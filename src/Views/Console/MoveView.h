#ifndef VIEWS_CONSOLE_MOVEVIEW_H_
#define VIEWS_CONSOLE_MOVEVIEW_H_

#include "../../Controllers/MoveController.h"
#include "LimitedIntDialogView.h"

namespace Views {
namespace Console {

class MoveView {
public:
	MoveView();
	virtual ~MoveView();

	void interact(Controllers::MoveController &moveController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_MOVEVIEW_H_ */
