#include "GameView.h"

namespace Views {
namespace Console {

GameView::GameView() {

}

GameView::~GameView() {
}

void GameView::interact(Controllers::InitialGameDecitionController &initialGameDecitionController) {
	assert(&initialGameDecitionController);

	(new BoardView(initialGameDecitionController.getBoard()))->write();
	LimitedIntDialogView limitedIntDialogView(*(new Utils::LimitedIntDialog("Enter the action you want to do [1=Move Card, 2=Flip Cards, 3=Undo, 4=Redo]", 1, 4)));
	limitedIntDialogView.write();
	int option = limitedIntDialogView.read();
	switch (option) {
	case 1:
		initialGameDecitionController.setInitialGameDecition(Controllers::InitialGameDecition::MOVE_CARDS);
		initialGameDecitionController.execute();
		break;
	case 2:
		initialGameDecitionController.setInitialGameDecition(Controllers::InitialGameDecition::FLIP_CARDS);
		initialGameDecitionController.execute();
		break;
	case 3:
		initialGameDecitionController.setInitialGameDecition(Controllers::InitialGameDecition::UNDO);
		initialGameDecitionController.execute();
		break;
	case 4:
		initialGameDecitionController.setInitialGameDecition(Controllers::InitialGameDecition::REDO);
		initialGameDecitionController.execute();
		break;
	default:
		assert(false);
	}
}

} /* namespace Console */
} /* namespace Views */
