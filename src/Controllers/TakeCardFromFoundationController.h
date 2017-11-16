#ifndef CONTROLLERS_TAKECARDFROMFOUNDATIONCONTROLLER_H_
#define CONTROLLERS_TAKECARDFROMFOUNDATIONCONTROLLER_H_

#include "TakeCardController.h"

namespace Controllers {

class TakeCardFromFoundationController : public virtual TakeCardController{
public:
	virtual Error checkChoice(int sourceFoundationIndex) = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_TAKECARDFROMFOUNDATIONCONTROLLER_H_ */
