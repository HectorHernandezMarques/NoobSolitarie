/*
 * Stack.h
 *
 *  Created on: Oct 1, 2017
 *      Author: AntonioMontana
 */

#ifndef UTILS_STACK_H_
#define UITLS_STACK_H_

#include <cassert>
#include "Node.h"

namespace Utils {

template<class T>
class Stack {
private:
	Node<T>* getWithReferences(int index);
	Node<T>* firstItem;
	Node<T>* lastItem;
	int itemsNumber = 0;

protected:

public:
	Stack();
	Stack(Node<T> &item);
	virtual ~Stack();

	void add(Node<T> &item);
	Node<T>& remove(int index);
	Node<T>& removeUntilEnd(int index);
	T& get(int index);
	T& getLast() {
		return this->get(this->itemsNumber - 1);
	}
	int getIndex(T &item);

	int getItemsNumber() {
		return this->itemsNumber;
	}
};

template<class T> Stack<T>::Stack() {
	this->firstItem = nullptr;
	this->lastItem = nullptr;
	this->itemsNumber = 0;
}

template<class T> Stack<T>::Stack(Node<T> &item) :
		Stack() {
	assert(&item);
	assert(item.getElement());
	assert(!item.getPreviousElement());

	this->add(item);
}

template<class T> Stack<T>::~Stack() {
}

template<class T> void Stack<T>::add(Node<T> &item) {
	assert(&item);
	assert(item.getElement());
	assert(!item.getPreviousElement());

	if (!this->firstItem) {
		this->firstItem = &item;
		this->lastItem = &item;
		this->itemsNumber++;
	} else {
		this->lastItem->setNextElement(&item);
		item.setPreviousElement(this->lastItem);
	}

	for (; this->lastItem->getNextElement(); this->itemsNumber++) {
		this->lastItem = this->lastItem->getNextElement();
	}
}

template<class T> Node<T>& Stack<T>::remove(int index) {
	assert(this->itemsNumber);
	assert(0 <= index && index < this->itemsNumber);

	Node<T> *currentItem = this->getWithReferences(index);

	if (currentItem->getPreviousElement()) {
		currentItem->getPreviousElement()->setNextElement(currentItem->getNextElement());
	} else {
		this->firstItem = currentItem->getNextElement();
	}
	if (currentItem->getNextElement()) {
		currentItem->getNextElement()->setPreviousElement(currentItem->getPreviousElement());
	} else {
		this->lastItem = currentItem->getPreviousElement();
	}
	this->itemsNumber--;

	currentItem->setNextElement(nullptr);
	currentItem->setPreviousElement(nullptr);
	return *currentItem;
}

template<class T> Node<T>& Stack<T>::removeUntilEnd(int index) {
	assert(this->itemsNumber);
	assert(0 <= index && index < this->itemsNumber);

	Node<T> *currentItem = this->getWithReferences(index);

	if (currentItem->getPreviousElement()) {
		currentItem->getPreviousElement()->setNextElement(nullptr);
	} else {
		this->firstItem = nullptr;
	}
	this->lastItem = currentItem->getPreviousElement();
	currentItem->setPreviousElement(nullptr);
	this->itemsNumber = index;
	return *currentItem;
}

template<class T> T& Stack<T>::get(int index) {
	assert(this->itemsNumber);
	assert(0 <= index && index < this->itemsNumber);

	return *this->getWithReferences(index)->getElement();
}

template<class T> Node<T>* Stack<T>::getWithReferences(int index) {
	assert(this->itemsNumber);
	assert(0 <= index && index < this->itemsNumber);

	Node<T> *currentItem = this->firstItem;
	for (int i = 0; i < index; i++) {
		currentItem = currentItem->getNextElement();
	}
	return currentItem;
}

template<class T> int Stack<T>::getIndex(T &item) {
	assert(this->itemsNumber);

	Node<T> *currentItem = this->firstItem;
	int i;
	for (i = 0; *currentItem->getElement() != item && i < this->itemsNumber; i++) {
		currentItem = currentItem->getNextElement();
	}
	assert(i <= this->itemsNumber);
	return i;
}

} /* namespace Utils */

#endif /* STACK_H_ */
