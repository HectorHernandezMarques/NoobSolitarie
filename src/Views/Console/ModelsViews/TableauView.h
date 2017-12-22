#ifndef VIEWS_CONSOLE_MODELS_TABLEAUVIEW_H_
#define VIEWS_CONSOLE_MODELS_TABLEAUVIEW_H_

#include "../../ModelView.h"
#include "../../../Models/Tableau.h"
#include "../../../Utils/IO.h"
#include "./CardView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

class TableauView: public ModelView {
private:
	Models::Tableau &tableau;
public:
	TableauView(Models::Tableau &tableau);
	virtual ~TableauView();

	void write();
};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_MODELS_TABLEAUVIEW_H_ */
