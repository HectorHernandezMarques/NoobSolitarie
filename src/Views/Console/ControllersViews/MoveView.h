#ifndef VIEWS_CONSOLE_CONTROLLERS_MOVEVIEW_H_
#define VIEWS_CONSOLE_CONTROLLERS_MOVEVIEW_H_

#include "../../../Controllers/MoveController.h"
#include "../ModelsViews/LimitedIntDialogView.h"
#include "../ModelsViews/BoardView.h"
#include "../ModelsViews/CardChoiceView.h"
#include "./TakeCardFromFoundationView.h"
#include "./TakeCardFromTableauView.h"
#include "./TakeCardFromStockView.h"
#include "./PutCardInFoundationView.h"
#include "./PutCardInTableauView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

class MoveView {
public:
	MoveView();
	virtual ~MoveView();

	void interact(Controllers::MoveController &moveController);
};

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CONTROLLERS_MOVEVIEW_H_ */
