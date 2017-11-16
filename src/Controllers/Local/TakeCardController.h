#ifndef CONTROLLERS_LOCAL_TAKECARDCONTROLLER_H_
#define CONTROLLERS_LOCAL_TAKECARDCONTROLLER_H_

#include "../TakeCardController.h"
#include "Controller.h"

namespace Controllers {
namespace Local {

class TakeCardController: public virtual Controllers::TakeCardController, public Controllers::Local::Controller {
protected:
	CardChoice *cardChoice;

public:
	TakeCardController(Models::Game &game);
	virtual ~TakeCardController();

	CardChoice& getCardChoice();
};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_TAKECARDCONTROLLER_H_ */
