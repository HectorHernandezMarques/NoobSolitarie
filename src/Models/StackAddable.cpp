#include "StackAddable.h"

namespace Models{

StackAddable::StackAddable() :
		Stack() {
}

StackAddable::StackAddable(Utils::Node<Cards::Card> &card) :
		Stack(card) {
}
StackAddable::~StackAddable() {
}

} /* namespace Models */
