/*
 * Error.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: eherhes
 */
#include "Error.h"

namespace Controllers {

const Error Error::CANT_FLIP = Error("Can't flip cards.");
const Error Error::CANT_TAKE_FROM_FOUNDATION = Error("Can't take cards from this Foundation.");
const Error Error::CANT_TAKE_FROM_TABLEAU = Error("Can't take cards from this Tableau.");
const Error Error::CANT_TAKE_FROM_STOCK = Error("Can't take cards from the Stock.");
const Error Error::CANT_TAKE_CARD = Error("Can't take that card(s).");
const Error Error::CANT_PUT_CARD = Error("Can't put that card(s) here.");
const Error Error::NO_ERROR = *(new Error("NO ERROR HAPPENED HERE, YOU CAN SLEEP IN A SUITABLE WAY"));

Error::Error(std::string message) {
	this->message = message;
}

Error::~Error() {
}

std::string Error::getMessage() {
	return this->message;
}

} /* namespace Controllers */
