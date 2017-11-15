#include "OperationController.h"

namespace Controllers {
namespace Local {

OperationController::OperationController(Models::Game &game) : Controllers::Local::Controller(game) {
	assert(&game);
}

OperationController::~OperationController() {
}

} /* namespace Local */
} /* namespace Controllers */
