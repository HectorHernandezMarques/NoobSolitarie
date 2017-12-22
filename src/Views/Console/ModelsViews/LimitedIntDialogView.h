#ifndef VIEWS_CONSOLE_LIMITEDINTDIALOGVIEW_H_
#define VIEWS_CONSOLE_LIMITEDINTDIALOGVIEW_H_

#include "../../ModelView.h"
#include "../../../Utils/LimitedIntDialog.h"
#include "./ClosedIntervalView.h"

namespace Views {
namespace Console {
namespace ModelsViews {

class LimitedIntDialogView : public ModelView{
private:
	Utils::LimitedIntDialog &limitedIntDialog;

public:
	LimitedIntDialogView(Utils::LimitedIntDialog &limitedIntDialog);
	virtual ~LimitedIntDialogView();

	void write();
	int read();
};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_LIMITEDINTDIALOGVIEW_H_ */
