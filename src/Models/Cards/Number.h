#ifndef NUMBER_H_
#define NUMBER_H_

#include <cassert>

namespace Models{
namespace Cards {

class Number {
private:
protected:
	int number;
	int maxNumber;

public:
	Number();
	Number(int number, int maxNumber);
	virtual ~Number();


	bool isFirst();
	bool isLast();
	bool isNextOf(Number &cardNumber);
	bool operator==(Number &cardNumber);

	int getNumber();

};

} /* namespace Cards */
} /* namespace Models */

#endif /* NUMBER_H_ */
