#include "FlipView.h"

namespace Views {
namespace Console {

FlipView::FlipView() {
}

FlipView::~FlipView() {
}

void FlipView::interact(Controllers::FlipController &flipController) {
	Controllers::Error error = flipController.flip();
	if(error == Controllers::Error::CANT_FLIP){
		Utils::IO io = Utils::IO::getInstance();
		io.writeln("Can't flip");
	}
}

} /* namespace Console */
} /* namespace Views */
