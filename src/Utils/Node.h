#ifndef UTILS_NODE_H_
#define UTILS_NODE_H_

namespace Utils{

template<class T>
class Node {
private:
	T *element;
	Node *nextElement;
	Node *previousElement;

public:
	Node();
	Node(T* element, Node *previousElement, Node *nextElement);
	virtual ~Node();

	void cleanNextElement();
	void cleanPreviousElement();

	T* getElement() {
		return this->element;
	}
	Node<T>* getNextElement() {
		return this->nextElement;
	}
	Node<T>* getPreviousElement() {
		return this->previousElement;
	}

	void setElement(T *element) {
		this->element = element;
	}
	void setNextElement(Node<T> *nextElement) {
		this->nextElement = nextElement;
	}
	void setPreviousElement(Node<T> *previousElement) {
		this->previousElement = previousElement;
	}

};

template<class T> Node<T>::Node() {
	this->element = nullptr;
	this->nextElement = nullptr;
	this->previousElement = nullptr;
}

template<class T> Node<T>::Node(T *element, Node *previousElement, Node *nextElement) {
	this->element = element;
	this->nextElement = nextElement;
	this->previousElement = previousElement;
}

template<class T> Node<T>::~Node() {
}

template<class T> void Node<T>::cleanNextElement() {
	this->nextElement = nullptr;
}

template<class T> void Node<T>::cleanPreviousElement() {
	this->previousElement = nullptr;
}

} /* namespace Utils */

#endif /* UTILS_NODE_H_ */
