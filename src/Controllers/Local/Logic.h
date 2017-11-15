#ifndef CONTROLLERS_LOCAL_LOGIC_H_
#define CONTROLLERS_LOCAL_LOGIC_H_

#include "../Logic.h"
#include "InitialGameDecitionController.h"
#include "FlipController.h"
#include "MoveController.h"
#include "StartController.h"

namespace Controllers {
namespace Local {

class Logic : public Controllers::Logic{
public:
	Logic();
	virtual ~Logic();

	Controllers::Local::OperationController& getOperationController();

};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_LOGIC_H_ */
