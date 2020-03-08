# include <iostream>
using namespace std;

template <class T>
class node1 {

public:
	node1 *prev;
	T value;
	node1 *next;
	node1(node1 *p, T v, node1 *n) {
		prev = p;
		value = v;
		next = n;
	}
	node1()
	{
		next = NULL;
		prev = NULL;
	}
	~node1() {
		cout << "node1 destroyed: " << value << endl;
	}

};
template <class T>
class DLL {
	node1<T> *tail, *head;
public:
	DLL();
	~DLL();
	void addToHead(T v);
	void addToTail(T v);
	void deleteHead();
	void deleteTail();
	void print();
	bool Deletenode1(T val);
	void append(DLL &l2);
	void insertInOrder(T v);
	void MergeInOrder(DLL<T>& l2);
	bool Search(T v) {
		node1<T> *p = head;
		while (p != NULL) {
			if (p->value == v)
				return true;
			p = p->next;
		}
		return false;
	}
	void duplicate(DLL<T>& l2) {
		node1<T> *p = head;
		while (p != NULL) {
			T v = p->value;
			if (l2.Search(v)) {
				node1<T> *newnode1 = new node1<T>(p, v, p->next);
				if (p != tail) {
					p->next->prev = newnode1;
					p->next = newnode1;
				}
				else {
					p->next = newnode1;
					tail = newnode1;

				}
				p = p->next;
			}
			p = p->next;
		}
	}
	void clear() {
		node1<T> *temp = head;
		while (temp != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
		head = tail = NULL;
	}
	void AddTwoLists(DLL<T> & l2, DLL<T> & R) {
		node1<T> *p1, *p2;
		p1 = head;
		p2 = l2.head;

		while (p1 != NULL) {
			T v1 = p1->value;
			T v2 = p2->value;
			R.addToTail(v1 + v2);
			p1 = p1->next;
			p2 = p2->next;
		}
	}


};
template <class T>
void DLL<T>::MergeInOrder(DLL<T>& l2)
{
	DLL<T> l3;
	node1<T> *p1, *p2;
	p1 = head;
	p2 = l2.head;

	while (p1 != NULL || p2 != NULL) {
		if (p1 == NULL) {
			l3.addToTail(p2->value);
			p2 = p2->next;
		}
		else if (p2 == NULL) {
			l3.addToTail(p1->value);
			p1 = p1->next;
		}
		else if (p1->value < p2->value) {
			l3.addToTail(p1->value);
			p1 = p1->next;
		}
		else {
			l3.addToTail(p2->value);
			p2 = p2->next;
		}
	}
	// fill original list with values from l3;
	clear();
	head = l3.head;
	tail = l3.tail;
	l3.head = l3.tail = NULL;
}
template <class T>
void DLL<T>::insertInOrder(T v) {
	//

	if (head == NULL) {
		addToHead(v);
	}
	else if (head->value >= v) {
		addToHead(v);
	}
	else	if (tail->value <= v){
		addToTail(v);
	}

	else  {
		node1<T> * temp = head;
		node1<T> *newnode1 = new node1<T>(NULL, v, NULL);
		while (temp != NULL) {
			if (temp->value<v) {
				temp = temp->next;
			}
			else {
				node1<T> *p = temp->prev;
				p->next = newnode1;
				newnode1->prev = p;
				newnode1->next = temp;
				temp->prev = newnode1;
				break;
			}
		}

	}
}

template <class T>
void DLL<T>::append(DLL &l2) {

	node1<T> *t = l2.head;

	while (t != NULL) {
		addToTail(t->value);

		t = t->next;
	}

}

template <class T>
bool DLL<T>::Deletenode1(T v) {
	node1<T> *temp = head;

	if (head->value == v)
	{
		deleteHead();
		return true;
	}
	if (tail->value == v)
	{
		deleteTail();
		return true;
	}
	while (temp != NULL) {
		if (temp->value == v) {
			node1<T> *p = temp->prev;
			node1<T> *n = temp->next;
			p->next = n;
			n->prev = p;
			delete temp;
			return true;
			/*temp->prev->next = temp->next;
			temp->next->prev = temp->prev;*/
		}
		temp = temp->next;
	}
	return false;
}

template <class T>
void DLL<T>::deleteHead() {
	node1<T>*t = head;

	if (head == NULL)
		return;
	else if (head == tail){
		delete t;
		head = tail = NULL;
	}
	else {
		head = head->next;
		delete t;
		head->prev = NULL;
	}

}

template <class T>
void DLL<T>::deleteTail() {

	if (head == NULL)
		return;
	else if (head == tail) {
		delete head;
		head = tail = NULL;
	}
	else {
		node1<T>*t = tail->prev;
		delete tail;
		tail = t;
		tail->next = NULL;
	}

}

template <class T>
DLL<T>::DLL() {
	head = tail = NULL;
}
template <class T>
DLL<T>::~DLL() {
	//node1<T> *temp = head;
	//while (temp->next != NULL) {
	//	head = head->next;
	//	delete temp;
	//	temp = head;
	//}
	////head = tail = NULL;
}
template <class T>
void DLL<T>::addToHead(T v) {
	node1<T> *newnode1 = new node1<T>(NULL, v, head);

	if (head == NULL) {
		head = tail = newnode1;
		head->next = NULL;
		head->prev = NULL;
	}
	else {
		head->prev = newnode1;
		newnode1->next = NULL;
		newnode1->next = head;
		head = newnode1;
	}
}
template <class T>
void DLL<T>::print() {
	node1<T> * t = head; //tail
	cout << "NULL <--";
	while (t != NULL) {
		cout << t->value << "<=>";
		t = t->next; //prev
	}
	cout << "NULL \n";

}
template <class T>
void DLL<T>::addToTail(T v) {
	node1<T>* newnode1 = new node1<T>(tail, v, NULL);

	if (head == NULL)
		head = tail = newnode1;
	else {
		tail->next = newnode1;
		tail = newnode1;
	}


};