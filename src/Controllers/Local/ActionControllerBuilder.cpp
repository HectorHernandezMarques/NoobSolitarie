#include "./ActionControllerBuilder.h"

namespace Controllers {
namespace Local {

ActionControllerBuilder::ActionControllerBuilder(Models::Game &game) {
	this->actionControllers.push_back(new Controllers::Local::MoveController(game));
	this->actionControllers.push_back(new Controllers::Local::FlipController(game));
	this->actionControllers.push_back(new Controllers::Local::UndoController(game));
	this->actionControllers.push_back(new Controllers::Local::RedoController(game));
}

ActionControllerBuilder::~ActionControllerBuilder() {
}

std::list<Controllers::ActionController*> ActionControllerBuilder::getAvailableCommands() {
	std::list<Controllers::ActionController*> result;
	for(auto it = this->actionControllers.begin(); it != this->actionControllers.end(); ++it) {
		if((*it)->available()) {
			result.push_back(&(*it)->clone());
		}
	}

	return result;
}

} /* namespace Local */
} /* namespace Controllers */
