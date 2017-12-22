#include "MoveController.h"

namespace Controllers {
namespace Local {

MoveController::MoveController(Models::Game &game) :
		Controllers::Local::ActionController(game) {
	assert(&game);
}

MoveController::MoveController(const MoveController &rhs) : MoveController(rhs.game){
	assert(&game);
}

MoveController::~MoveController() {
}

void MoveController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

bool MoveController::available() {
	return !this->game.isGameOver();
}

Controllers::Error MoveController::execute() {
	assert(&this->takeCardController);
	assert(&this->putCardController);

	Controllers::Error result = this->putCardController->execute();
	if (result == Controllers::Error::NO_ERROR) {
		this->takeCardController->execute();
		this->game.takeMemento();
	}
	this->setState(Models::State::IN_GAME);

	return result;
}

Controllers::TakeCardFromFoundationController& MoveController::getTakeCardFromFoundationController(){
	this->takeCardController = new Controllers::Local::TakeCardFromFoundationController(this->game);
	return *(Controllers::Local::TakeCardFromFoundationController*) this->takeCardController;
}

Controllers::TakeCardFromTableauController& MoveController::getTakeCardFromTableauController(){
	this->takeCardController = new Controllers::Local::TakeCardFromTableauController(this->game);
	return *(Controllers::Local::TakeCardFromTableauController*) this->takeCardController;
}

Controllers::TakeCardFromStockController& MoveController::getTakeCardFromStockController(){
	this->takeCardController = new Controllers::Local::TakeCardFromStockController(this->game);
	return *(Controllers::Local::TakeCardFromStockController*) this->takeCardController;
}

Controllers::PutCardController& MoveController::getPutCardInFoundationController(CardChoice& cardChoice){
	this->putCardController = new Controllers::Local::PutCardInFoundationController(this->game, cardChoice);
	return *this->putCardController;
}

Controllers::PutCardController& MoveController::getPutCardInTableauController(CardChoice &cardChoice){
	this->putCardController = new Controllers::Local::PutCardInTableauController(this->game, cardChoice);
	return *this->putCardController;
}

InitialGameDecition MoveController::getName() {
	return InitialGameDecition::MOVE;
}

Controllers::ActionController& MoveController::clone() {
	return *new MoveController(*this);
}

} /* namespace Local */
} /* namespace Controller */
