/*
 * Node.h
 *
 *  Created on: Oct 2, 2017
 *      Author: AntonioMontana
 */

#ifndef NODE_H_
#define NODE_H_

template <class T>
class Node {
private:
	T *element;
	Node *nextElement;
	Node *previousElement;

public:
	Node(){
		this->element = nullptr;
		this->nextElement = nullptr;
		this->previousElement = nullptr;
	};
	Node(T* element, Node *previousElement, Node *nextElement){
		this->element = element;
		this->nextElement = nextElement;
		if(nextElement)
		{
			nextElement->setPreviousElement(this);
		}
		this->previousElement = previousElement;
		if(previousElement)
		{
			previousElement->setNextElement(this);
		}
	};
	virtual ~Node(){};

	T* getElement() { return this->element; }
	Node* getNextElement() { return this->nextElement; }
	Node* getPreviousElement() { return this->previousElement; }

	void setElement(T* element) { this->element = element; }
	void setNextElement(Node *nextElement) { this->nextElement = nextElement; }
	void setPreviousElement(Node *previousElement) { this->previousElement = previousElement; }

};

#endif /* NODE_H_ */
