# include<iostream>
# include "Queue.h"
# include "Stack.h"
# include "DLL.h"
using namespace std;
template <class T>
class BST;

template <class T>
class node {
	friend class BST<T>;
	T val;
	node<T> * left, *right;
public:
	node(node<T> *l, T v, node<T> *r) {
		val = v;
		left = l;
		right = r;

	}
	~node() {
		cout << "node destroyed: " << val << endl;
	}
};
template <class T>
class BST {
	node<T> * root;
public:
	BST() {
		root = NULL;
	}
	~BST() {}
	void insert(T v) {
		node<T> *newNode = new node<T>(NULL, v, NULL);

		if (root == NULL)
		{
			root = newNode;
		}
		else {
			node<T> * temp = root;
			node<T> * parent = NULL;

			while (temp != NULL) {
				parent = temp;
				if (newNode->val > temp->val) {
					temp = temp->right;
				}
				else {
					temp = temp->left;
				}
			}
			if (newNode->val > parent->val)
				parent->right = newNode;
			else
				parent->left = newNode;

		}

	}
	void BFT() {
		if (root == NULL)
			return;
		QueueArr<node<T> *> myQ;
		myQ.Enqueue(root);
		while (!myQ.isEmpty()) {
			node<T> *temp = myQ.Dequeue();
			cout << temp->val << " , ";
			if (temp->left != NULL)
				myQ.Enqueue(temp->left);
			if (temp->right != NULL)
				myQ.Enqueue(temp->right);
		}
		cout << endl;
	}
	T getMin() {
		if (root != NULL) {
			node<T> *temp = root;
			while (temp->left != NULL)
				temp = temp->left;
			return temp->val;
		}
		else
		{
			cout << "Tree is empty\n";
			exit(0);
		}
	}
	T getMax() {
		if (root != NULL) {
			node<T> *temp = root;
			while (temp->right != NULL)
				temp = temp->right;
			return temp->val;
		}
		else
		{
			cout << "Tree is empty\n";
			exit(0);
		}
	}
	bool search(T v) {
		node<T> * temp = root;
		while (temp != NULL) {
			if (temp->val == v)
				return true;
			else if (temp->val < v)
				temp = temp->right;
			else
				temp = temp->left;
		}
		return false;
	}

	bool search(T v, node<T> *n) {
		if (n == NULL)
			return false;
		if (n->val == v)
			return true;
		if (v > n->val)
			return search(v, n->right);
		else
			return search(v, n->left);

	}


	bool isEmpty() { return root == NULL; }
	void preorder() {
		node<T> *temp = root;
		StackArr<node<T> *> mystack;

		if (root == NULL)
			return;
		mystack.push(temp);
		while (mystack.isEmpty() == false) {
			node<T> *t = mystack.pop();
			cout << t->val << " , ";
			if (t->right != NULL)
				mystack.push(t->right);
			if (t->left != NULL)
				mystack.push(t->left);
		}
		cout << endl;
	}
	void postorder() {
		node<T> *temp = root;
		StackArr<node<T> *> s1, s2;
		if (root == NULL)
			return;
		s1.push(temp);
		while (!s1.isEmpty()) {
			node<T> *t = s1.pop();
			s2.push(t);
			if (t->left != NULL)
				s1.push(t->left);
			if (t->right != NULL)
				s1.push(t->right);
		}
		while (!s2.isEmpty()) {
			node<T> *t2 = s2.pop();
			cout << t2->val << " , ";
		}
		cout << endl;
	}

	void preorder(node<T> *n) {
		if (n == NULL)
			return;
		cout << n->val << " , ";
		preorder(n->left);
		preorder(n->right);

	}
	void postorder(node<T> *n) {
		if (n == NULL)
			return;

		postorder(n->left);
		postorder(n->right);
		cout << n->val << " , ";

	}
	node<T>* getRoot() {
		return root;
	}
	void inorder(node<T> *n) {
		if (n == NULL)
			return;

		inorder(n->left);
		cout << n->val << " , ";
		inorder(n->right);


	}

	bool deleteNode(T v) {
		node<T> *parent, *node = root;
		parent = NULL;

		while (node != NULL) {
			if (node->val == v){
				break;
			}
			if (v > node->val){
				parent = node;
				node = node->right;
			}
			if (v < node->val){
				parent = node;
				node = node->left;
			}
		}
		if (node == NULL)
			return false;
		if (node->left == NULL || node->right == NULL)
			deleteSingle(node, parent);
		else
			deleteDouble(node);
		return true;
	}

	void deleteSingle(node<T> *n, node<T> *parent) {

		if (root == n) {
			if (root->left != NULL)
				root = root->left;
			else
				root = root->right;
		}
		else {
			if (parent->left == n) {
				if (n->left != NULL)
					parent->left = n->left;
				else
					parent->left = n->right;
			}
			else {
				if (n->left != NULL)
					parent->right = n->left;
				else
					parent->right = n->right;


			}


		}
		delete n;

	}
	void deleteDouble(node<T> *n) {

		node<T> *p = n->left;
		node<T> *parent = n;
		while (p->right != NULL) {
			parent = p;
			p = p->right;

		}
		T temp = n->val;
		n->val = p->val;
		p->val = temp;
		deleteSingle(p, parent);
	}

	void clear() {
		clear(root);
		root = NULL;
	}
	void clear(node<T> *n) {
		if (n == NULL)
			return;
		clear(n->left);
		clear(n->right);
		delete n;
	}
	int count(node<T> *n, int &count) {



	}
	void HelperSimilarNodes(node<T>*&root, int & counter)
	{
		if (root == NULL)
			return;
		if (search(root->val))
			counter++;
		HelperSimilarNodes(root->left, counter);
		HelperSimilarNodes(root->right, counter);
	}
	// returns number of similar nodes in this and Tree2
	int SimilarNodes(BST&Tree2)
	{
		int counter = 0;
		HelperSimilarNodes(Tree2.root, counter);
		return counter;
	}
	int height(node<T>* root, int& ans, node<T>*(&k), int& lh, int& rh, int& f)
	{
		if (root == NULL)
			return 0;
		int left_height = height(root->left, ans, k, lh, rh, f);
		int right_height = height(root->right, ans, k, lh, rh, f);

		if (ans < 1 + left_height + right_height) {
			ans = 1 + left_height + right_height;
			k = root;
			lh = left_height;
			rh = right_height;
		}

		return 1 + max(left_height, right_height);
	}
	int max(int left_height, int right_height)
	{
		if (left_height > right_height)
			return left_height;
		else
			return right_height;
	}
	// returns DLL of longest branch
	DLL<T> getBranch()
	{
		int ans = INT_MIN, lh = 0, rh = 0, f = 0;
		node<T>* k = NULL;
		int treeHeight = height(root, ans, k, lh, rh, f);
		int path[100], pathlen = treeHeight;
		return printPathsRecur(root, path, pathlen, treeHeight, f);
	}
	void helperSplitTree(T&v, BST&Tree1, BST&Tree2, node<T>*root)
	{
		if (root == NULL)
			return;
		if (root->val < v)
			Tree1.insert(root->val);
		else
			Tree2.insert(root->val);

		helperSplitTree(v, Tree1, Tree2, root->left);
		helperSplitTree(v, Tree1, Tree2, root->right);
	}
	// split original tree on value v, if less -> Tree, otherwise Tree2
	void splitTree(T&v, BST&Tree1, BST&Tree2)
	{
		helperSplitTree(v, Tree1, Tree2, root);
		this->clear();
	}

	bool helperIsSubTree(node<T> * root1, node<T> *root2)
	{
		if (root1 == NULL && root2 == NULL)
			return true;
		if (root2 == NULL)
			return true;
		if (root1 == NULL && root2 != NULL)
			return false;
		return (root1->val == root2->val && helperIsSubTree(root1->left, root2->left) && helperIsSubTree(root1->right, root2->right));
	}

	int isSubTree(node<T>*root, node<T>*root2)
	{
		if (root2 == NULL)
			return true;
		if (root == NULL)
			return false;
		if (helperIsSubTree(root, root2))
			return true;
		bool x = isSubTree(root->left, root2) || isSubTree(root->right, root2);
		return x;
	}

	bool isSubTree(BST&Tree2)
	{
		return isSubTree(root, Tree2.root);
	}
	DLL<T> getDLL(T path[], int pathLen)
	{
		DLL<T> dll;// = new DLL<T>();
		for (int i = 0; i < pathLen; i++)
		{
			if (search(path[i]))
				dll.addToHead(path[i]);
		}
		return dll;
	}
	DLL<T> printPathsRecur(node<T>* root, int path[], int pathLen, int max, int& f)
	{
		if (root == NULL)
			return getDLL(path, 0);
		
		path[pathLen] = root->val;
		pathLen++;

		if (root->left == NULL && root->right == NULL) {

			if (pathLen >= max && (f == 0 || f == 1)) {
				return getDLL(path, pathLen);
				f = 2;
			}
		}
		else {

			printPathsRecur(root->left, path, pathLen, max, f);
			printPathsRecur(root->right, path, pathLen, max, f);
		}
		return getDLL(path, 0);
	}

};
int main() {
	int a[] = { 4, 2, 1, 3, 6, 5, 7 };

	int b[] = {10, 4, 2, 1, 3, 6, 5, 7, 15, 20, 13, 18, 20, 18};
	BST<int> myTree;
	BST<int> myTree1;
	BST<int> myTree2;
	BST<int> myTree3;

	for (int i = 0; i < 7; i++)
		myTree.insert(a[i]);
	for (int i = 0; i < 14; i++)
		myTree1.insert(b[i]);
	cout << "PreOrder of First Tree : ";
	myTree.preorder(); cout << endl;
	cout << "PreOrder of Second Tree : ";
	myTree1.preorder(); cout << endl;
	cout << "Is Sub Tree : " << myTree.isSubTree(myTree);
	cout << endl;
	cout << "PreOrder of First Tree : ";
	myTree.preorder(); cout << endl;
	cout << "PreOrder of Second Tree : ";
	myTree1.preorder(); cout << endl;
	int sn = myTree.SimilarNodes(myTree1);
	cout <<"Similar Nodes : "<< sn << endl;
	cout << endl; cout << endl;

	int splitter = 7;
	cout << "Before Splitting "; cout << endl;
	cout << "PreOrder of Original Tree : ";
	myTree1.preorder(); cout << endl;
	cout << "PreOrder of First Tree : ";
	myTree2.preorder(); cout << endl;
	cout << "PreOrder of Second Tree : ";
	myTree3.preorder(); cout << endl;
	myTree1.splitTree(splitter, myTree2, myTree3);
	cout << "After Splitting "; cout << endl;
	cout << "PreOrder of Original Tree : ";
	myTree1.preorder(); cout << endl;
	cout << "PreOrder of First Tree : ";
	myTree2.preorder(); cout << endl;
	cout << "PreOrder of Second Tree : ";
	myTree3.preorder(); cout << endl;
	
	DLL<int> dll = myTree.getBranch();
	dll.print();
	system("pause");
	return 0;
}