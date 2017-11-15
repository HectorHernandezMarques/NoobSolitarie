#ifndef VIEWS_CONSOLE_STARTVIEW_H_
#define VIEWS_CONSOLE_STARTVIEW_H_

#include "../../Controllers/StartController.h"
#include "BoardView.h"

namespace Views {
namespace Console {

class StartView{
public:
	StartView();
	virtual ~StartView();

	void interact(Controllers::StartController &startController);
};

} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_STARTVIEW_H_ */
