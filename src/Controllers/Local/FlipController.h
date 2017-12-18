#ifndef CONTROLLERS_LOCAL_FLIPCONTROLLER_H_
#define CONTROLLERS_LOCAL_FLIPCONTROLLER_H_

#include "ActionController.h"
#include "../FlipController.h"

namespace Controllers {
namespace Local {

class FlipController: public virtual Controllers::FlipController, public Controllers::Local::ActionController {
private:
public:
	FlipController(Models::Game &game);
	virtual ~FlipController();

	void accept(ActionControllerVisitor &actionControllerVisitor);
	Controllers::Error execute();

};

} /* namespace Local */
} /* namespace Controller */

#endif /* CONTROLLERS_LOCAL_FLIPCONTROLLER_H_ */
