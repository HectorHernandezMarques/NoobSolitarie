#include "Game.h"

namespace Models {

Game::Game() :
		board(BoardBuilder().getBoard()), state(State::INITIAL) {
}

Game::~Game() {
}

bool Game::canFlip() {
	return this->board.canFlip();
}

void Game::flip() {
	return this->board.flip();
}

void Game::setState(State state) {
	assert(&state);

	this->state = state;
}

Board& Game::getBoard() {
	return this->board;
}

int Game::getSuitNumberMax() {
	return this->board.getSuitNumberMax();
}

int Game::getTableausNumberMax() {
	return this->board.getTableausNumberMax();
}

Tableau& Game::getTableau(int index) {
	return this->board.getTableau(index);
}

Foundation& Game::getFoundation(int index) {
	return this->board.getFoundation(index);
}

Stock& Game::getStock() {
	return this->board.getStock();
}

State Game::getState() {
	return this->state;
}

int Game::getVisibleCardsNumberFromTableau(int index){
	return this->board.getVisibleCardsNumberFromTableau(index);
}

} /* namespace Models */
