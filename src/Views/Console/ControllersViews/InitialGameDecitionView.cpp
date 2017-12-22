#include "./InitialGameDecitionView.h"

namespace Views {
namespace Console {
namespace ControllersViews {

InitialGameDecitionView::InitialGameDecitionView() {

}

InitialGameDecitionView::~InitialGameDecitionView() {
}

void InitialGameDecitionView::interact(Controllers::InitialGameDecitionController &initialGameDecitionController) {
	assert(&initialGameDecitionController);

	(new ModelsViews::BoardView(initialGameDecitionController.getBoard()))->write();

	auto availableCommandsNames = initialGameDecitionController.getAvailableCommandsNames();
	assert(availableCommandsNames.size());

	std::string message = "Enter the action you want to do [";
	int i = 1;
	for(auto it = availableCommandsNames.begin(); it!= availableCommandsNames.end(); ++it) {
		message += std::to_string(i++) + "=" +(new ModelsViews::InitialGameDecitionNameView(*it))->toString() + ", ";
	}
	message += "]";

	ModelsViews::LimitedIntDialogView limitedIntDialogView(*(new Utils::LimitedIntDialog(message, 1, availableCommandsNames.size())));
	limitedIntDialogView.write();

	int option = limitedIntDialogView.read() - 1;

	auto it = availableCommandsNames.begin();
	std::advance(it, option);
	initialGameDecitionController.setInitialGameDecition(*(it));
	initialGameDecitionController.execute();
}

} /* namespace ControllersViews */
} /* namespace Console */
} /* namespace Views */
