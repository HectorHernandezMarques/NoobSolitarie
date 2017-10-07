/*
 * Game.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Game.h"
#include "Pile.h"
#include "Suit.h"
#include "RemainderDeck.h"

Game::Game() :
		deck() {

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

Game::~Game() {
}

void Game::run() {
	int option[2][3];
	for (;;) {
		system("CLS");
		std::cout << this->printGame();
		if (this->firstDecition(option[0])) {
			switch (option[0][0]) {
			case 0:
				if (this->suit[option[0][1]]->checkRemove(0)) {
					this->secondDecition(option[1]);

					switch (option[1][0]) {
					case 0:
						if (this->suit[option[1][1]]->checkAdd(
								this->suit[option[0][1]]->checkRemove(0))) {
							this->suit[option[1][1]]->add(
									this->suit[option[0][1]]->remove(0));
						} else {
							std::cout << "Invalid destiny";
						}
						break;
					case 1:
						if (this->pile[option[1][1]]->checkAdd(
								this->suit[option[0][1]]->checkRemove(0))) {
							this->pile[option[1][1]]->add(
									this->suit[option[0][1]]->remove(0));
						} else {
							std::cout << "Invalid destiny";
						}
						break;
					}
				} else {
					std::cout << "Invalid card";
				}
				break;
			case 1:
				if (this->pile[option[0][1]]->checkRemove(option[0][2])) {
					this->secondDecition(option[1]);

					switch (option[1][0]) {
					case 0:
						if (this->suit[option[1][1]]->checkAdd(
								this->pile[option[0][1]]->checkRemove(
										option[0][2]))) {
							this->suit[option[1][1]]->add(
									this->pile[option[0][1]]->remove(
											option[0][2]));
						} else {
							std::cout << "Invalid destiny";
						}
						break;
					case 1:
						if (this->pile[option[1][1]]->checkAdd(
								this->pile[option[0][1]]->checkRemove(
										option[0][2]))) {
							this->pile[option[1][1]]->add(
									this->pile[option[0][1]]->remove(
											option[0][2]));
						} else {
							std::cout << "Invalid destiny";
						}
						break;
					}
				} else {
					std::cout << "Invalid card";
				}
				break;
			case 2:
				if (this->remainderDeck->checkRemove(0)) {
					this->secondDecition(option[1]);

					switch (option[1][0]) {
					case 0:
						if (this->suit[option[1][1]]->checkAdd(
								this->remainderDeck->checkRemove(0))) {
							this->suit[option[1][1]]->add(
									this->remainderDeck->remove(0));
						} else {
							std::cout << "Invalid destiny";
						}
						break;
					case 1:
						if (this->pile[option[1][1]]->checkAdd(
								this->remainderDeck->checkRemove(0))) {
							this->pile[option[1][1]]->add(
									this->remainderDeck->remove(0));
						} else {
							std::cout << "Invalid destiny";
						}
						break;
					}
				} else {
					std::cout << "Invalid card";
				}
				break;
			}

		} else {
			this->remainderDeck->add(nullptr);
		}
	}
}

bool Game::firstDecition(int *option) {
	do {
		std::cout
				<< "Enter the section you want to access [0=Suits(top), 1=Piles(middle), 2=Deck(bottom)]";
		std::cin >> option[0];
	} while (option[0] != 0 && option[0] != 1 && option[0] != 2);
	switch (option[0]) {
	case 0:
		do {
			std::cout << "Enter the Suit you want to access [0 .. "
					<< SUIT_NUMBER - 1 << "]";
			std::cin >> option[1];
		} while (option[1] < 0 || option[1] >= SUIT_NUMBER);
		break;
	case 1:
		do {
			std::cout << "Enter the Pile you want to access [0 .. "
					<< PILES_NUMBER - 1 << "]";
			std::cin >> option[1];
		} while (option[1] < 0 || option[1] >= PILES_NUMBER);

		do {
			std::cout << "Enter the card you want to access [0 .. "
					<< (this->pile[option[1]]->getCardsNumber()
							- ((Pile*) this->pile[option[1]])->getHiddenCards())
							- 1 << "]";
			std::cin >> option[2];
		} while (option[2] < 0
				|| option[2]
						>= (this->pile[option[1]]->getCardsNumber()
								- ((Pile*) this->pile[option[1]])->getHiddenCards()));

		break;
	case 2:
		do {
			std::cout
					<< "Enter the Option you want to choose [0=New card(s), 1=Take Card]";
			std::cin >> option[1];
		} while (option[1] != 0 && option[1] != 1);
		break;
	}
	return !(option[0] == 2 && option[1] == 0);
}

void Game::secondDecition(int *option) {
	do {
		std::cout
				<< "Enter the section you want to insert your card(s) [0=Suits(top), 1=Piles(middle)]";
		std::cin >> option[0];
	} while (option[0] != 0 && option[0] != 1);
	switch (option[0]) {
	case 0:
		do {
			std::cout
					<< "Enter the Suit where you want to insert your card(s) [0 .. "
					<< SUIT_NUMBER - 1 << "]";
			std::cin >> option[1];
		} while (option[1] < 0 || option[1] >= SUIT_NUMBER);
		break;
	case 1:
		do {
			std::cout
					<< "Enter the Pile where you want to insert your card(s) [0 .. "
					<< PILES_NUMBER - 1 << "]";
			std::cin >> option[1];
		} while (option[1] < 0 || option[1] >= PILES_NUMBER);

		break;
	}
}

std::string Game::printGame() {
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
