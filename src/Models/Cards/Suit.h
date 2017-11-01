#ifndef SUIT_H_
#define SUIT_H_

#include <cassert>

namespace Models{
namespace Cards {

class Suit {
private:
protected:
	int suit;
public:
	Suit();
	Suit(int suit);
	virtual ~Suit();

	bool isSameParityOf(Suit &suit);
	bool operator==(Suit &suit);
};

} /* namespace Cards */
} /* namespace Models */

#endif /* SUIT_H_ */
