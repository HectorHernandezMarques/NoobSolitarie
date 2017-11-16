#ifndef CONTROLLERS_TAKECARDFROMTABLEAUCONTROLLER_H_
#define CONTROLLERS_TAKECARDFROMTABLEAUCONTROLLER_H_

#include "TakeCardController.h"

namespace Controllers {

class TakeCardFromTableauController : public virtual TakeCardController{
public:
	virtual Error checkChoice(int sourceTableauIndex, int relativeSourceCardIndex) = 0;
	virtual int getVisibleCardsNumberFromTableau(int index) = 0;
};

} /* namespace Controller */

#endif /* CONTROLLERS_TAKECARDFROMTABLEAUCONTROLLER_H_ */
