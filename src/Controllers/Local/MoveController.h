#ifndef CONTROLLERS_LOCAL_MOVECONTROLLER_H_
#define CONTROLLERS_LOCAL_MOVECONTROLLER_H_

#include "../MoveController.h"
#include "ActionController.h"
#include "TakeCardFromFoundationController.h"
#include "TakeCardFromTableauController.h"
#include "TakeCardFromStockController.h"
#include "PutCardInFoundationController.h"
#include "PutCardInTableauController.h"

namespace Controllers {
namespace Local {

class MoveController: public virtual Controllers::MoveController, public Controllers::Local::ActionController {
public:
	MoveController(Models::Game &game);
	virtual ~MoveController();

	void accept(ActionControllerVisitor &actionControllerVisitor);

	Controllers::TakeCardFromFoundationController& getTakeCardFromFoundationController();
	Controllers::TakeCardFromTableauController& getTakeCardFromTableauController();
	Controllers::TakeCardFromStockController& getTakeCardFromStockController();

	Controllers::PutCardController& getPutCardInFoundationController(CardChoice &cardChoice);
	Controllers::PutCardController& getPutCardInTableauController(CardChoice &cardChoice);
};

} /* namespace Local */
} /* namespace Controller */

#endif /* CONTROLLERS_LOCAL_MOVECONTROLLER_H_ */
