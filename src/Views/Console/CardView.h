#ifndef VIEWS_CONSOLE_CARDVIEW_H_
#define VIEWS_CONSOLE_CARDVIEW_H_

#include "../ModelView.h"
#include "../../Models/Cards/Card.h"
#include "SuitView.h"
#include "NumberView.h"


namespace Views {
namespace Console {

class CardView: public ModelView {
private:
	Models::Cards::Card &card;

public:
	CardView(Models::Cards::Card &card);
	virtual ~CardView();

	void write();
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_CARDVIEW_H_ */
