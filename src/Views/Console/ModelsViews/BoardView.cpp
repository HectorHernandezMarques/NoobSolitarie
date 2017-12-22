#include "./BoardView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

BoardView::BoardView(Models::Board &board) : board(board){
}

BoardView::~BoardView() {
}

void BoardView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	system("CLS");
	io.writeln("");
	for (int i = 0; i < this->board.getSuitNumberMax(); i++) {
		(new FoundationView(this->board.getFoundation(i)))->write();
	}
	io.writeln("\n");
	for (int i = 0; i < this->board.getTableausNumberMax(); i++) {
		(new TableauView(this->board.getTableau(i)))->write();
		io.writeln("");
	}
	io.writeln("\n");
	(new StockView(this->board.getStock()))->write();
	io.writeln("\n");
}

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */
