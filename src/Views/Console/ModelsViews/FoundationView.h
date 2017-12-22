#ifndef VIEWS_CONSOLE_MODELS_FOUNDATIONVIEW_H_
#define VIEWS_CONSOLE_MODELS_FOUNDATIONVIEW_H_

#include "../../ModelView.h"
#include "../../../Models/Foundation.h"
#include "../../../Utils/IO.h"
#include "./CardView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

class FoundationView: public ModelView {
private:
	Models::Foundation &foundation;

public:
	FoundationView(Models::Foundation &foundation);
	virtual ~FoundationView();

	void write();

};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_MODELS_FOUNDATIONVIEW_H_ */
