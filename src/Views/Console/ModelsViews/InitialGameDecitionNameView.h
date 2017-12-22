#ifndef VIEWS_CONSOLE_MODELSVIEWS_INITIALGAMEDECITIONNAMEVIEW_H_
#define VIEWS_CONSOLE_MODELSVIEWS_INITIALGAMEDECITIONNAMEVIEW_H_

#include "../../ModelView.h"
#include "../../../Controllers/InitialGameDecition.h"
#include "../../../Utils/IO.h"

namespace Views {
namespace Console {
namespace ModelsViews {

class InitialGameDecitionNameView: public ModelView {
private:
	Controllers::InitialGameDecition initialGameDecition;

public:
	InitialGameDecitionNameView(Controllers::InitialGameDecition initialGameDecition);
	virtual ~InitialGameDecitionNameView();

	void write();
	std::string toString();
};

} /* namespace ModelsViews */
} /* namespace Console */
} /* namespace Views */

#endif /* VIEWS_CONSOLE_MODELSVIEWS_INITIALGAMEDECITIONNAMEVIEW_H_ */
