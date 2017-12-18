#ifndef CONTROLLERS_LOCAL_TAKECARDFROMSTOCKCONTROLLER_H_
#define CONTROLLERS_LOCAL_TAKECARDFROMSTOCKCONTROLLER_H_

#include "../TakeCardFromStockController.h"
#include "TakeCardController.h"

namespace Controllers {
namespace Local {

class TakeCardFromStockController: public virtual Controllers::TakeCardFromStockController,
		public Controllers::Local::TakeCardController {
public:
	TakeCardFromStockController(Models::Game &game);
	virtual ~TakeCardFromStockController();

	Controllers::Error setChoice();
};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_TAKECARDFROMSTOCKCONTROLLER_H_ */
