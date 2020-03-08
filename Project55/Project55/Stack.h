#pragma once
# include <iostream>
using namespace std;
template <class T>
class StackArr {
	int capacity;
	int last;
	T *arr;
public:
	StackArr() {
		last = -1;
		capacity = 3;
		arr = new T[capacity];
	}
	StackArr(int cap) {
		last = -1;
		capacity = cap;
		arr = new T[capacity];
	}
	~StackArr() {
		delete[] arr;
	}

	void push(T v)
	{
		if (last == capacity - 1) {
			T *temp = new T[capacity + 5];
			for (int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
			temp = NULL;
			capacity = capacity + 5;

		}
		last++;
		arr[last] = v;
	}
	T pop() {
		if (last == -1)
			exit(0);
		T temp = arr[last];
		last--;
		return temp;
	}
	T Top() {
		if (last == -1)
			return -1; // exit(0);
		return arr[last];
	}
	void print() {
		cout << "\n printing stack values with capacity: " << capacity << endl;;
		for (int i = 0; i <= last; i++)
			cout << arr[i] << " - ";
		cout << endl;
	}
	bool isFull() { return last == capacity - 1; }
	bool isEmpty() { return last == -1; }
	void clear() {
		last = -1;
	}
};
