#ifndef VIEWS_CONSOLE_BOARDVIEW_H_
#define VIEWS_CONSOLE_BOARDVIEW_H_

#include "../ModelView.h"
#include "FoundationView.h"
#include "TableauView.h"
#include "StockView.h"
#include "../../Models/Board.h"
#include "../../Utils/IO.h"

namespace Views {
namespace Console {

class BoardView : public ModelView{
private:
	Models::Board &board;

public:
	BoardView(Models::Board &board);
	virtual ~BoardView();

	void write();

};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_BOARDVIEW_H_ */
