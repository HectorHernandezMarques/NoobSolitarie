/*
 * Game.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include "NoobSolitarie.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Pile.h"
#include "Suit.h"
#include "RemainderDeck.h"

NoobSolitarie::NoobSolitarie() :
		deck(), IO() {

	srand(time(nullptr));
	int nextCard;
	int servedCards = 0;
	Node<Card>* currentNode;

	for (int i = 0; i < PILES_NUMBER; i++) {
		currentNode = nullptr;

		for (int j = 0; j <= i; j++) {
			nextCard = rand() % (SUIT_NUMBER * CARDS_PER_SUIT);

			for (; this->deck.getServedCards(nextCard);) {
				nextCard = (nextCard + 1) % (SUIT_NUMBER * CARDS_PER_SUIT);
			}

			currentNode = new Node<Card>(this->deck.getCard(nextCard),
					currentNode, nullptr);
			this->deck.setServedCards(nextCard, true);
			servedCards++;
		}

		this->pile[i] = new Pile(currentNode);
	}

	currentNode = nullptr;

	for (int j = servedCards; j < (SUIT_NUMBER * CARDS_PER_SUIT); j++) {
		nextCard = rand() % (SUIT_NUMBER * CARDS_PER_SUIT);

		for (; this->deck.getServedCards(nextCard);) {
			nextCard = (nextCard + 1) % (SUIT_NUMBER * CARDS_PER_SUIT);
		}

		currentNode = new Node<Card>(this->deck.getCard(nextCard), currentNode,
				nullptr);
		this->deck.setServedCards(nextCard, true);
	}

	this->remainderDeck = new RemainderDeck(currentNode);

	for (int i = 0; i < SUIT_NUMBER; i++) {
		this->suit[i] = new Suit();
	}

}

NoobSolitarie::~NoobSolitarie() {
}

void NoobSolitarie::run() {
	int option[2][3];
	for (;;) {
		system("CLS");
		this->IO.writeln(this->toString());
		if (this->firstDecition(option[0])) {
			switch (option[0][0]) {
			case 0:
				if (this->suit[option[0][1]]->canRemove(0)) {
					this->secondDecition(option[1]);

					switch (option[1][0]) {
					case 0:
						if (this->suit[option[1][1]]->canAdd(
								this->suit[option[0][1]]->canRemove(0))) {
							this->suit[option[1][1]]->add(
									this->suit[option[0][1]]->remove(0));
						} else {
							this->IO.writeln("Invalid destiny");
						}
						break;
					case 1:
						if (this->pile[option[1][1]]->canAdd(
								this->suit[option[0][1]]->canRemove(0))) {
							this->pile[option[1][1]]->add(
									this->suit[option[0][1]]->remove(0));
						} else {
							this->IO.writeln("Invalid destiny");
						}
						break;
					}
				} else {
					this->IO.writeln("Invalid card");
				}
				break;
			case 1:
				if (this->pile[option[0][1]]->canRemove(option[0][2])) {
					this->secondDecition(option[1]);

					switch (option[1][0]) {
					case 0:
						if (this->suit[option[1][1]]->canAdd(
								this->pile[option[0][1]]->canRemove(
										option[0][2]))) {
							this->suit[option[1][1]]->add(
									this->pile[option[0][1]]->remove(
											option[0][2]));
						} else {
							this->IO.writeln("Invalid destiny");
						}
						break;
					case 1:
						if (this->pile[option[1][1]]->canAdd(
								this->pile[option[0][1]]->canRemove(
										option[0][2]))) {
							this->pile[option[1][1]]->add(
									this->pile[option[0][1]]->remove(
											option[0][2]));
						} else {
							this->IO.writeln("Invalid destiny");
						}
						break;
					}
				} else {
					this->IO.writeln("Invalid card");
				}
				break;
			case 2:
				if (this->remainderDeck->canRemove(0)) {
					this->secondDecition(option[1]);

					switch (option[1][0]) {
					case 0:
						if (this->suit[option[1][1]]->canAdd(
								this->remainderDeck->canRemove(0))) {
							this->suit[option[1][1]]->add(
									this->remainderDeck->remove(0));
						} else {
							this->IO.writeln("Invalid destiny");
						}
						break;
					case 1:
						if (this->pile[option[1][1]]->canAdd(
								this->remainderDeck->canRemove(0))) {
							this->pile[option[1][1]]->add(
									this->remainderDeck->remove(0));
						} else {
							this->IO.writeln("Invalid destiny");
						}
						break;
					}
				} else {
					this->IO.writeln("Invalid card");
				}
				break;
			}

		} else {
			this->remainderDeck->add(nullptr);
		}
	}
}

bool NoobSolitarie::firstDecition(int *option) {
	do {
		option[0] =
				this->IO.readInt(
						"Enter the section you want to access [0=Suits(top), 1=Piles(middle), 2=Deck(bottom)]");
	} while (option[0] != 0 && option[0] != 1 && option[0] != 2);
	switch (option[0]) {
	case 0:
		do {
			option[1] = this->IO.readInt(
					"Enter the Suit you want to access [0 .. "
							+ std::to_string(SUIT_NUMBER - 1) + "]");
		} while (option[1] < 0 || option[1] >= SUIT_NUMBER);
		break;
	case 1:
		do {
			option[1] = this->IO.readInt(
					"Enter the Pile you want to access [0 .. "
							+ std::to_string(PILES_NUMBER - 1) + "]");
		} while (option[1] < 0 || option[1] >= PILES_NUMBER);

		do {
			option[2] = this->IO.readInt("Enter the card you want to access [0 .. "
							+ std::to_string(
									(this->pile[option[1]]->getCardsNumber()
											- ((Pile*) this->pile[option[1]])->getHiddenCardsNumber())
											- 1) + "]");
		} while (option[2] < 0
				|| option[2]
						>= (this->pile[option[1]]->getCardsNumber()
								- ((Pile*) this->pile[option[1]])->getHiddenCardsNumber()));

		break;
	case 2:
		do {
			option[1] = this->IO.readInt("Enter the Option you want to choose [0=New card(s), 1=Take Card]");
		} while (option[1] != 0 && option[1] != 1);
		break;
	}
	return !(option[0] == 2 && option[1] == 0);
}

void NoobSolitarie::secondDecition(int *option) {
	do {
		option[0] = this->IO.readInt("Enter the section you want to insert your card(s) [0=Suits(top), 1=Piles(middle)]");
	} while (option[0] != 0 && option[0] != 1);
	switch (option[0]) {
	case 0:
		do {
			option[1] = this->IO.readInt("Enter the Suit where you want to insert your card(s) [0 .. "
							+ std::to_string(SUIT_NUMBER - 1) + "]");
		} while (option[1] < 0 || option[1] >= SUIT_NUMBER);
		break;
	case 1:
		do {
			option[1] = this->IO.readInt("Enter the Pile where you want to insert your card(s) [0 .. "
							+ std::to_string(PILES_NUMBER - 1) + "]");
		} while (option[1] < 0 || option[1] >= PILES_NUMBER);

		break;
	}
}

std::string NoobSolitarie::toString() {
	std::string result = "\n";

	for (int i = 0; i < SUIT_NUMBER; i++) {
		result += this->suit[i]->print() + "  ";
	}

	result += "\n\n";

	for (int i = 0; i < PILES_NUMBER; i++) {
		result += std::to_string(i) + " - " /*+ std::to_string(this->pile[i]->getCardsNumber()) + " - "*/
		+ this->pile[i]->print() + "\n";
	}

	result += "\n\n";

	result += "     " + this->remainderDeck->print() + "\n\n";

	return result;
}
