#ifndef CONTROLLERS_TAKECARDFROMSTOCKCONTROLLER_H_
#define CONTROLLERS_TAKECARDFROMSTOCKCONTROLLER_H_

#include "TakeCardController.h"

namespace Controllers {

class TakeCardFromStockController : public virtual TakeCardController{
public:
	virtual Error setChoice() = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_TAKECARDFROMSTOCKCONTROLLER_H_ */
