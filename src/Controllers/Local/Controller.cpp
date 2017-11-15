#include "Controller.h"

namespace Controllers {
namespace Local {

Controller::Controller(Models::Game &game) :
		game(game) {
	assert(&game);
}

Controller::~Controller() {

}

void Controller::setState(Models::State state) {
	this->game.setState(state);
}

Models::State Controller::getState() {
	return this->game.getState();
}

Models::Board& Controller::getBoard() {
	return this->game.getBoard();
}
int Controller::getSuitNumberMax() {
	return this->game.getSuitNumberMax();
}

int Controller::getTableausNumberMax() {
	return this->game.getTableausNumberMax();
}

Models::Tableau& Controller::getTableau(int index) {
	return this->game.getTableau(index);
}

Models::Foundation& Controller::getFoundation(int index) {
	return this->game.getFoundation(index);
}

Models::Stock& Controller::getStock() {
	return this->game.getStock();
}

} /* namespace Local */
} /* namespace Controllers */
