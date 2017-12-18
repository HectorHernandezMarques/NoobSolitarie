#ifndef CONTROLLERS_PUTCARDCONTROLLER_H_
#define CONTROLLERS_PUTCARDCONTROLLER_H_

#include "ActionController.h"
#include "CardChoice.h"

namespace Controllers {

class PutCardController : public virtual Controller{
private:
	virtual Models::StackAddable& getStackAddable(int targetStackIndex) = 0;

public:
	virtual void setTargetChoice(int targetStackIndex) = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_TAKECARDONTROLLER_H_ */
