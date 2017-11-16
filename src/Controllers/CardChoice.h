#ifndef CONTROLLERS_CARDCHOICE_H_
#define CONTROLLERS_CARDCHOICE_H_

#include "../Models/Cards/Card.h"
#include "../Models/Stack.h"
#include "../Models/StackAddable.h"

namespace Controllers {

class CardChoice {
private:
	Models::Stack *stack;
	Utils::Stack<Models::Cards::Card> &cards;

public:
	CardChoice(Models::Stack *stack, Utils::Stack<Models::Cards::Card> &card);
	virtual ~CardChoice();

	bool canAddInStack(Models::StackAddable &stackAddable);
	void removeCard();

	Utils::Stack<Models::Cards::Card>& getCards();
	Models::Stack& getStack();
};

} /* namespace Controllers */

#endif /* CONTROLLERS_CARDCHOICE_H_ */
