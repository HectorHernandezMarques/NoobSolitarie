#ifndef CONTROLLERS_ERROR_H_
#define CONTROLLERS_ERROR_H_

#include <string>

namespace Controllers {

enum class Error {CANT_FLIP,
	CANT_TAKE_FROM_FOUNDATION,
	CANT_TAKE_FROM_TABLEAU,
	CANT_TAKE_FROM_STOCK,
	CANT_TAKE_CARD,
	CANT_PUT_CARD,
	NO_ERROR
};

}
/* namespace Controllers */

#endif /* CONTROLLERS_ERROR_H_ */
