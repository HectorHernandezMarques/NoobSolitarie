#ifndef UTILS_STACK_H_
#define UITLS_STACK_H_

#include <cassert>
#include <list>

namespace Utils {

template<class T>
class Stack {
private:
	std::list<T> list;

protected:

public:
	Stack();
	Stack(T &item);
	Stack(Stack<T> &item);
	Stack(std::list<T> &item);
	virtual ~Stack();

	void add(T &item);
	void add(Stack<T> &items);
	Stack<T>& remove(unsigned int index);
	Stack<T>& removeUntilEnd(unsigned int index);
	T& get(unsigned int index);
	T& getLast();
	int getIndex(T &item);
	Stack<T>& getUntilEnd(unsigned int index);
	int getItemsNumber();
};

template<class T> Stack<T>::Stack() :
		list(0) {
}

template<class T> Stack<T>::Stack(T &item) :
		list(1, item) {
	assert(&item);
}

template<class T> Stack<T>::Stack(Stack<T> &items) :
		list(items.list) {
	assert(&items);
}

template<class T> Stack<T>::Stack(std::list<T> &items) :
		list(items) {
	assert(&items);
}

template<class T> Stack<T>::~Stack() {
}

template<class T> void Stack<T>::add(T &item) {
	assert(&item);

	this->list.push_back(item);
}

template<class T> void Stack<T>::add(Stack<T> &items) {
	assert(&items);

	this->list.splice(list.end(), items.list);
}

template<class T> Stack<T>& Stack<T>::remove(unsigned int index) {
	assert(this->list.size());
	assert(0 <= index && index < this->list.size());

	auto it = this->list.begin();
	std::advance(it, index);
	std::list<T> tempList;
	tempList.insert(tempList.end(), *it);
	this->list.erase(it);
	return *new Stack<T>(tempList);
}

template<class T> Stack<T>& Stack<T>::removeUntilEnd(unsigned int index) {
	assert(this->list.size());
	assert(0 <= index && index < this->list.size());

	auto it = this->list.begin();
	std::advance(it, index);
	std::list<T> tempList(it, this->list.end());
	this->list.erase(it, this->list.end());
	return *new Stack<T>(tempList);
}

template<class T> T& Stack<T>::get(unsigned int index) {
	assert(this->list.size());
	assert(0 <= index && index < this->list.size());

	auto it = this->list.begin();
	std::advance(it, index);

	return *it;
}

template<class T> T& Stack<T>::getLast() {
	assert(this->list.size());

	return this->get(this->getItemsNumber() - 1);
}

template<class T> int Stack<T>::getIndex(T &item) {
	assert(this->list.size());
	assert(&item);

	int i = 0;
	auto it = this->list.begin();
	for (; it != this->list.end() && *it != item; ++it) {
		i++;
	}
	assert(it != this->list.end());
	return i;
}

template<class T> Stack<T>& Stack<T>::getUntilEnd(unsigned int index) {
	assert(this->list.size());
	assert(0 <= index && index < this->list.size());

	auto it = this->list.begin();
	std::advance(it, index);
	std::list<T> tempList(it, this->list.end());
	return *new Stack<T>(tempList);
}

template<class T> int Stack<T>::getItemsNumber() {
	return this->list.size();
}

} /* namespace Utils */

#endif /* STACK_H_ */
