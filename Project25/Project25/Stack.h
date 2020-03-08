#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Array.h"

template <class T>
class Stack {
public:
	Stack() : els(2), top(-1) { }

	void push(const T & el);
	bool pop(T & el);
	bool peek(T & el);
	bool isEmpty() const { return (top == -1); }
	void makeEmpty() { top = -1; }
private:
	Array<T> els; // dynamic array els
	int top;
};

template <class T>
void Stack<T>::push(const T & el) { // 1 element: top = 0; 2 elements: top = 1, ...
	++top;
	if (els.length() == top) {
		els.changeSize(els.length() * 2);
	}
	els[top] = el;
}

template <class T>
bool Stack<T>::pop(T & el) { // we need to remove els[top]
	if (top == -1) return false;
	el = els[top];
	top--;
	return true;
}

template <class T>
bool Stack<T>::peek(T & el) { // we need to remove els[top]
	if (top == -1) return false;
	el = els[top];
	return true;
}


#endif // STACK_H_INCLUDED
