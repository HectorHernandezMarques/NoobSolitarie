#ifndef VIEWS_CONSOLE_GAMEVIEW_H_
#define VIEWS_CONSOLE_GAMEVIEW_H_

#include "../../Controllers/InitialGameDecitionController.h"
#include "../../Controllers/InitialGameDecition.h"
#include "BoardView.h"
#include "LimitedIntDialogView.h"

namespace Views {
namespace Console {

class GameView{
public:
	GameView();
	virtual ~GameView();

	void interact(Controllers::InitialGameDecitionController &initialGameDecitionController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_GAMEVIEW_H_ */
