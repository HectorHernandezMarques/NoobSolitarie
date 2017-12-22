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
private:
	TakeCardController *takeCardController;
	PutCardController *putCardController;

public:
	MoveController(Models::Game &game);
	MoveController(const MoveController &game);
	virtual ~MoveController();

	void accept(ActionControllerVisitor &actionControllerVisitor);
	bool available();
	Controllers::Error execute();

	Controllers::TakeCardFromFoundationController& getTakeCardFromFoundationController();
	Controllers::TakeCardFromTableauController& getTakeCardFromTableauController();
	Controllers::TakeCardFromStockController& getTakeCardFromStockController();

	Controllers::PutCardController& getPutCardInFoundationController(CardChoice &cardChoice);
	Controllers::PutCardController& getPutCardInTableauController(CardChoice &cardChoice);

	InitialGameDecition getName();
	Controllers::ActionController& clone();
};

} /* namespace Local */
} /* namespace Controller */

#endif /* CONTROLLERS_LOCAL_MOVECONTROLLER_H_ */
