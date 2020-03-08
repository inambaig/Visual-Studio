#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class Array {
public:
	Array(int s);
	Array(const Array<T> & arr);
	Array<T> & operator = (const Array<T> & arr);
	~Array();

	int length() const { return size; }
	T & operator [](int index);
	void changeSize(int newSize);
	int errCode() const { return err; }
private:
	T * els;
	int size;
	int err;
	T dud;
	void deepCopy(const Array<T> & arr);
};

template <class T>
Array<T>::Array(int s) {
	if (s < 1) { err = 1; s = 1; }
	else err = 0;
	size = s;
	els = new T[size];
}

template <class T>
Array<T>::Array(const Array<T> & arr) {
	deepCopy(arr);
}

template <class T>
Array<T> & Array<T>::operator = (const Array<T> & arr) {
	if (this == &arr) return *this;
	delete[] els;
	deepCopy(arr);
	return *this;
}

template <class T>
void Array<T>::deepCopy(const Array<T> & arr) {
	size = arr.size;
	err = arr.err;
	els = new T[size];
	for (int i = 0; i < size; i++) { els[i] = arr.els[i]; }
}

template <class T>
Array<T>::~Array() { delete[] els; }

template <class T>
T & Array<T>::operator [](int index) {
	if (index >= size) { err = err | 2; return dud; }
	return els[index];
}

template <class T>
void Array<T>::changeSize(int newSize) {
	if (newSize <= 0) { err = err | 4; return; }
	T * temp = new T[newSize];
	int limit = (size > newSize ? newSize : size);
	for (int i = 0; i < limit; i++) { temp[i] = els[i]; }
	delete[] els;
	els = temp; size = newSize;
}


#endif // ARRAY_H_INCLUDED
