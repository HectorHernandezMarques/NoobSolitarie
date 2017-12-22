#ifndef VIEWS_CONSOLE_MODELS_STOCKVIEW_H_
#define VIEWS_CONSOLE_MODELS_STOCKVIEW_H_

#include "../../ModelView.h"
#include "../../../Models/Stock.h"
#include "../../../Utils/IO.h"
#include "./CardView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

class StockView: public ModelView {
private:
	Models::Stock &stock;
public:
	StockView(Models::Stock &stock);
	virtual ~StockView();

	void write();
};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_MODELS_STOCKVIEW_H_ */
