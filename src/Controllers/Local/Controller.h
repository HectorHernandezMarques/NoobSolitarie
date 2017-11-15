#ifndef CONTROLLERS_LOCAL_CONTROLLER_H_
#define CONTROLLERS_LOCAL_CONTROLLER_H_

#include "../Controller.h"

namespace Controllers {
namespace Local {

class Controller : public virtual Controllers::Controller{
protected:
	Models::Game &game;

public:
	Controller(Models::Game &game);
	virtual ~Controller();

	void setState(Models::State state);
	Models::State getState();
	Models::Board& getBoard();
	int getSuitNumberMax();
	int getTableausNumberMax();
	Models::Tableau& getTableau(int index);
	Models::Foundation& getFoundation(int index);
	Models::Stock& getStock();

};

} /* namespace Local */
} /* namespace Controllers */

#endif /* CONTROLLERS_LOCAL_CONTROLLER_H_ */
