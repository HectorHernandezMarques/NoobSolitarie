#ifndef CONTROLLERS_LOCAL_LOGIC_H_
#define CONTROLLERS_LOCAL_LOGIC_H_

#include "../Logic.h"
#include "./InitialGameDecitionController.h"
#include "./StartController.h"
#include "./ActionControllerBuilder.h"

namespace Controllers {
namespace Local {

class Logic : public Controllers::Logic{
private:
	Models::Game game;
	ActionControllerBuilder actionControllerBuilder;

public:
	Logic();
	virtual ~Logic();

	Controllers::Local::OperationController& getOperationController();

};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_LOGIC_H_ */
