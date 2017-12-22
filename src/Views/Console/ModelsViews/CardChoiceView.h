#ifndef VIEWS_CONSOLE_MODELS_CARDCHOICEVIEW_H_
#define VIEWS_CONSOLE_MODELS_CARDCHOICEVIEW_H_

#include "../../ModelView.h"
#include "../../../Controllers/CardChoice.h"
#include "./CardView.h"
#include "../../../Utils/IO.h"

namespace Views {
namespace Console {
namespace ModelsViews {

class CardChoiceView: public ModelView {
private:
	Controllers::CardChoice &cardChoice;
public:
	CardChoiceView(Controllers::CardChoice &cardChoice);
	virtual ~CardChoiceView();

	void write();
};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_MODELS_CARDCHOICEVIEW_H_ */
