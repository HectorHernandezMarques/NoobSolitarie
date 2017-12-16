#ifndef CONTROLLERS_MOVECONTROLLER_H_
#define CONTROLLERS_MOVECONTROLLER_H_

#include "ActionController.h"
#include "TakeCardFromFoundationController.h"
#include "TakeCardFromTableauController.h"
#include "TakeCardFromStockController.h"
#include "PutCardController.h"


namespace Controllers {

class MoveController : public virtual ActionController{
public:
	virtual TakeCardFromFoundationController& getTakeCardFromFoundationController() = 0;
	virtual TakeCardFromTableauController& getTakeCardFromTableauController() = 0;
	virtual TakeCardFromStockController& getTakeCardFromStockController() = 0;

	virtual PutCardController& getPutCardInFoundationController(CardChoice& cardChoice) = 0;
	virtual PutCardController& getPutCardInTableauController(CardChoice &cardChoice) = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_MOVECONTROLLER_H_ */
