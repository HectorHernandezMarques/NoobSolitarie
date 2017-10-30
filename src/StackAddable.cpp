/*
 * StackAddable.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: eherhes
 */

#include "StackAddable.h"

StackAddable::StackAddable() :
		Stack() {
}

StackAddable::StackAddable(Utils::Node<Cards::Card> *card) :
		Stack(card) {
}
StackAddable::~StackAddable() {
}

