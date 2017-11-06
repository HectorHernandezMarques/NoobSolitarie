/*
 * Error.h
 *
 *  Created on: Nov 5, 2017
 *      Author: eherhes
 */

#ifndef CONTROLLERS_ERROR_H_
#define CONTROLLERS_ERROR_H_

#include <string>

namespace Controllers {

class Error {
private:
	std::string message;
	Error(std::string);

public:
	Error();
	virtual ~Error();
	std::string getMessage();

	static const Error CANT_FLIP;
	static const Error CANT_TAKE_FROM_FOUNDATION;
	static const Error CANT_TAKE_FROM_TABLEAU;
	static const Error CANT_TAKE_FROM_STOCK;
	static const Error CANT_TAKE_CARD;
	static const Error CANT_PUT_CARD;
	static const Error NO_ERROR;
};

} /* namespace Controllers */

#endif /* CONTROLLERS_ERROR_H_ */
