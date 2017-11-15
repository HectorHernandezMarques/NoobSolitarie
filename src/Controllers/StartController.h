#ifndef CONTROLLERS_STARTCONTROLLER_H_
#define CONTROLLERS_STARTCONTROLLER_H_

#include "OperationController.h"

namespace Controllers {

class StartController : public virtual OperationController{
public:
	virtual void start() = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_STARTCONTROLLER_H_ */
