#ifndef CONTROLLERS_TAKECARDCONTROLLER_H_
#define CONTROLLERS_TAKECARDCONTROLLER_H_

#include "ActionController.h"

#include "CardChoice.h"

namespace Controllers {

class TakeCardController : public virtual Controller{
public:

	virtual CardChoice& getCardChoice() = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_TAKECARDONTROLLER_H_ */
