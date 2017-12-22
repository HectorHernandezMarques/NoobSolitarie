#include "./StartView.h"
#include "../../../Controllers/StartController.h"

namespace Views {
namespace Console {
namespace ControllersViews {

StartView::StartView() {
}

StartView::~StartView() {
}

void StartView::interact(Controllers::StartController &startController) {
	assert(&startController);

	startController.execute();
}

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */
