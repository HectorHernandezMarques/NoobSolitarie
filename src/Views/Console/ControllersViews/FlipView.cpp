	#include "./FlipView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

FlipView::FlipView() {
}

FlipView::~FlipView() {
}

void FlipView::interact(Controllers::FlipController &flipController) {
	Controllers::Error error = flipController.execute();
	if(error == Controllers::Error::CANT_FLIP){
		Utils::IO io = Utils::IO::getInstance();
		io.writeln("Can't flip");
	}
}

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */
