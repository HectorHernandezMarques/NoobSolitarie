#include "LimitedIntDialogView.h"

namespace Views {
namespace Console {

LimitedIntDialogView::LimitedIntDialogView(Utils::LimitedIntDialog &limitedIntDialog) : limitedIntDialog(limitedIntDialog){
	assert(&limitedIntDialog);
}

LimitedIntDialogView::~LimitedIntDialogView() {
}

void LimitedIntDialogView::write() {
	Utils::IO &io = Utils::IO::getInstance();

	io.write(this->limitedIntDialog.getTitle());
	(new ClosedIntervalView(this->limitedIntDialog.getClosedInterval()))->write();
}

int LimitedIntDialogView::read() {
	Utils::IO &io = Utils::IO::getInstance();
	int result;
	do {
		result = io.readInt("");
	}while(!(this->limitedIntDialog.getMin() <= result && result <= this->limitedIntDialog.getMax()));

	return result;
}

} /* namespace Console */
} /* namespace Views */
