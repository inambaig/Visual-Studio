#pragma once
# include <iostream>
using namespace std;

template <class T>
class QueueArr {
	int front, end;
	int capacity;
	T *data;
	int c;
public:
	QueueArr() {
		c = 0;
		front = end = -1;
		capacity = 300;
		data = new T[capacity];
	}
	QueueArr(int cap) {
		c = 0;
		front = end = -1;
		capacity = cap;
		data = new T[capacity];
	}
	~QueueArr() {
		delete[] data;
	}

	void Enqueue(T v) {
		if (c == 0) {
			front = end = 0;
			data[end] = v;
			c++;
		}
		else if (c == capacity) {
			cout << "sorry queue is full\n";
		}
		else {
			if (end == capacity - 1) {
				end = 0;
				data[end] = v;
				c++;
			}
			else {
				end++;
				data[end] = v;
				c++;
			}
		}
	}
	T Dequeue() {
		if (c == 0) {
			cout << "queue is empty nothing to dequeue\n";
			exit(0);
		}
		else if (front == capacity - 1) {
			T v = data[front];
			front = 0;
			c--;
			return v;
		}
		else {
			T v = data[front];
			front++;
			c--;
			return v;
		}

	}
	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << data[i] << " , ";

		}
		cout << endl;
	}
	bool isEmpty() {
		return c == 0;
	}

};
