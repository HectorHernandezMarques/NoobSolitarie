#ifndef VIEWS_CONSOLE_SUITVIEW_H_
#define VIEWS_CONSOLE_SUITVIEW_H_

#include "../ModelView.h"
#include "../../Models/Cards/Suit.h"
#include "../../Utils/IO.h"
#include <cassert>

namespace Views {
namespace Console {

class SuitView: public ModelView {
private:
	Models::Cards::Suit &suit;

public:
	SuitView(Models::Cards::Suit &suit);
	virtual ~SuitView();

	void write();

};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_SUITVIEW_H_ */
