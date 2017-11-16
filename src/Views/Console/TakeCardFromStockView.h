#ifndef VIEWS_CONSOLE_TAKECARDFROMSTOCKVIEW_H_
#define VIEWS_CONSOLE_TAKECARDFROMSTOCKVIEW_H_

#include "TakeCardView.h"
#include "../../Controllers/TakeCardFromStockController.h"

namespace Views {
namespace Console {

class TakeCardFromStockView {
public:
	TakeCardFromStockView();
	virtual ~TakeCardFromStockView();

	Controllers::CardChoice& interact(Controllers::TakeCardFromStockController &takeCardFromStockController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_TAKECARDFROMSTOCKVIEW_H_ */
