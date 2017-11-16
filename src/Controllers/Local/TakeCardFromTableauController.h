#ifndef CONTROLLERS_LOCAL_TAKECARDFROMTABLEAUCONTROLLER_H_
#define CONTROLLERS_LOCAL_TAKECARDFROMTABLEAUCONTROLLER_H_

#include "../TakeCardFromTableauController.h"
#include "TakeCardController.h"

namespace Controllers {
namespace Local {

class TakeCardFromTableauController: public virtual Controllers::TakeCardFromTableauController,
		public Controllers::Local::TakeCardController {
public:
	TakeCardFromTableauController(Models::Game &game);
	virtual ~TakeCardFromTableauController();

	Error checkChoice(int sourceTableauIndex, int relativeSourceCardIndex);
	int getVisibleCardsNumberFromTableau(int index);
};

} /* namespace Controllers */
} /* namespace Local */

#endif /* CONTROLLERS_LOCAL_TAKECARDFROMTABLEAUCONTROLLER_H_ */
