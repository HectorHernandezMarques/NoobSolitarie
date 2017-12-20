#ifndef MODELS_GAME_H_
#define MODELS_GAME_H_

#include "BoardBuilder.h"
#include "State.h"
#include "./Memento/BoardMementoCareTaker.h"

namespace Models {

class Game {
private:
	Board board;
	Memento::BoardMementoCareTaker boardMementos;
	State state;
public:
	Game();
	virtual ~Game();

	bool canFlip();
	bool canUndo();
	bool canRedo();
	bool isGameOver();
	void takeMemento();
	void flip();
	void undo();
	void redo();

	void setState(State state);
	Board& getBoard();
	int getSuitNumberMax();
	int getTableausNumberMax();
	Tableau& getTableau(int index);
	Foundation& getFoundation(int index);
	Stock& getStock();
	State getState();

	int getVisibleCardsNumberFromTableau(int index);

};

} /* namespace Models */

#endif /* MODELS_GAME_H_ */
