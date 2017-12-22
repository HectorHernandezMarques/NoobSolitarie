#ifndef VIEWS_CONSOLE_MODELS_NUMBERVIEW_H_
#define VIEWS_CONSOLE_MODELS_NUMBERVIEW_H_

#include "../../ModelView.h"
#include "../../../Models/Cards/Number.h"
#include "../../../Utils/IO.h"
#include <cassert>

namespace Views {
namespace Console {
namespace ModelsViews {

class NumberView: public ModelView {
private:
	Models::Cards::Number &number;

public:
	NumberView(Models::Cards::Number &number);
	virtual ~NumberView();

	void write();

};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_MODELS_NUMBERVIEW_H_ */
