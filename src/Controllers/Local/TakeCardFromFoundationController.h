#ifndef CONTROLLERS_LOCAL_TAKECARDFROMFOUNDATIONCONTROLLER_H_
#define CONTROLLERS_LOCAL_TAKECARDFROMFOUNDATIONCONTROLLER_H_

#include "../TakeCardFromFoundationController.h"
#include "TakeCardController.h"

namespace Controllers {
namespace Local {

class TakeCardFromFoundationController: public virtual Controllers::TakeCardFromFoundationController,
		public Controllers::Local::TakeCardController {
private:

public:
	TakeCardFromFoundationController(Models::Game &game);
	virtual ~TakeCardFromFoundationController();

	Controllers::Error setChoice(int sourceFoundationIndex);
};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_TAKECARDFROMFOUNDATIONCONTROLLER_H_ */
