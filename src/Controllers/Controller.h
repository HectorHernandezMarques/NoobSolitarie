#ifndef CONTROLLERS_CONTROLLER_H_
#define CONTROLLERS_CONTROLLER_H_

#include "../Models/Game.h"
#include "Error.h"

namespace Controllers {

class Controller{
public:
	virtual Controllers::Error execute() = 0;

	virtual Models::State getState() = 0;
	virtual Models::Board& getBoard() = 0;
	virtual void setState(Models::State state) = 0;
	virtual int getSuitNumberMax() = 0;
	virtual int getTableausNumberMax() = 0;
	virtual Models::Tableau& getTableau(int index) = 0;
	virtual Models::Foundation& getFoundation(int index) = 0;
	virtual Models::Stock& getStock() = 0;
};

} /* namespace Controllers */

#endif /* CONTROLLERS_CONTROLLER_H_ */
