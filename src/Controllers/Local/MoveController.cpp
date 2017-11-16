#include "MoveController.h"

namespace Controllers {
namespace Local {

MoveController::MoveController(Models::Game &game) :
		Controllers::Local::ActionController(game) {
	assert(&game);
}

MoveController::~MoveController() {
}

void MoveController::accept(ActionControllerVisitor &actionControllerVisitor) {
	assert(&actionControllerVisitor);

	actionControllerVisitor.visit(*this);
}

Controllers::TakeCardFromFoundationController& MoveController::getTakeCardFromFoundationController(){
	return *new Controllers::Local::TakeCardFromFoundationController(this->game);
}

Controllers::TakeCardFromTableauController& MoveController::getTakeCardFromTableauController(){
	return *new Controllers::Local::TakeCardFromTableauController(this->game);
}

Controllers::TakeCardFromStockController& MoveController::getTakeCardFromStockController(){
	return *new Controllers::Local::TakeCardFromStockController(this->game);
}

Controllers::PutCardController& MoveController::getPutCardInFoundationController(CardChoice& cardChoice){
	return *new Controllers::Local::PutCardInFoundationController(this->game, cardChoice);
}

Controllers::PutCardController& MoveController::getPutCardInTableauController(CardChoice &cardChoice){
	return *new Controllers::Local::PutCardInTableauController(this->game, cardChoice);
}

} /* namespace Local */
} /* namespace Controller */
