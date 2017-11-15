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
	LimitedIntDialogView limitedIntDialogView(*(new Utils::LimitedIntDialog("Enter the action you want to do [1=Move Card, 2=Flip Cards]", 1, 2)));
	limitedIntDialogView.write();
	int option = limitedIntDialogView.read();
	switch (option) {
	case 1:
		initialGameDecitionController.makeDecition(Controllers::InitialGameDecition::MOVE_CARDS);
		break;
	case 2:
		initialGameDecitionController.makeDecition(Controllers::InitialGameDecition::FLIP_CARDS);
		break;
	default:
		assert(false);
	}
}

} /* namespace Console */
} /* namespace Views */
