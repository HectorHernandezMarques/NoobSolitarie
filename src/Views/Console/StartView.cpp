#include "StartView.h"

#include "../../Controllers/StartController.h"

namespace Views {
namespace Console {

StartView::StartView() {
}

StartView::~StartView() {
}

void StartView::interact(Controllers::StartController &startController) {
	assert(&startController);

	startController.start();
}

} /* namespace Console */
} /* namespace Views */
