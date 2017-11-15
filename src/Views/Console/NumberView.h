#ifndef VIEWS_CONSOLE_NUMBERVIEW_H_
#define VIEWS_CONSOLE_NUMBERVIEW_H_

#include "../ModelView.h"
#include "../../Models/Cards/Number.h"
#include "../../Utils/IO.h"
#include <cassert>

namespace Views {
namespace Console {

class NumberView: public ModelView {
private:
	Models::Cards::Number &number;

public:
	NumberView(Models::Cards::Number &number);
	virtual ~NumberView();

	void write();

};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_NUMBERVIEW_H_ */
