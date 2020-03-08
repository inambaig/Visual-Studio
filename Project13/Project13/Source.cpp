//#include<iostream> 
//using namespace std;
//struct link 
//{
//	int value; 
//	link * next; 
//}; 
//
//void disp(link*top)
//{link*
//	lptr = top;
//	while (lptr) {
//		cout << lptr->value;
//		lptr = lptr->next;
//	}
//}
//int main() {
//	link *top; 
//	link *current, *previous; 
//	link *lptr; 
//	int ivalue;
//	cout << "Input next value, -1 to terminate > " << flush; cin >> ivalue;
//	top = 0;
//	// Build the list 
//	while ( ivalue != -1 ) {
//	lptr = new link; 
//	lptr->value = ivalue; 
//	lptr->next = NULL;
//	current = top; 
//	previous = 0;
//	if (top == 0)
//	{
//		top = current = lptr;
//	}
//	else if (top->value >= ivalue)
//	{
//		lptr->next = top;
//		top = lptr;
//	}
//	else
//	{
//		bool inserted = false;
//		while (current->next != NULL)
//		{
//			if (current->value < ivalue && current->next->value >= ivalue)
//			{
//				inserted = true;
//				lptr->next = current->next;
//				current->next = lptr;
//			}
//			previous = current;
//			current = current->next;
//		}
//		if (!inserted)
//		{
//			if (current->value > ivalue)
//			{
//				if (previous == 0)
//				{
//					lptr->next = current;
//					top = lptr;
//				}
//				else
//				{
//					lptr->next = current;
//					previous->next = lptr;
//				}
//			}
//			else
//				current->next = lptr;
//		}
//	}
//	
//
//	cout << "Input next value, -1 to terminate > " << flush; 
//	cin >> ivalue;
//}
//	cout << "Linked list state after insertion : \n";
//lptr = top; 
//while (lptr) {
//	cout << lptr->value<<endl; 
//	lptr = lptr->next;
//}
//current = top; previous = 0;
////remove even values 
//while ( current ) {
//	if (current->next == NULL)
//	{
//		if (current->value % 2 == 0)
//		{
//			delete current;
//			current = top = NULL;
//			break;
//		}
//	}
//	if (previous == 0)
//	{
//		if (current->value % 2 == 0)
//		{
//			link*temp = current;
//			current = current->next;
//			delete temp;
//			temp = NULL;
//		}
//		else
//		{
//			previous = current;
//			current = current->next;
//		}
//	}
//	else
//	{
//		if (current->value % 2 == 0)
//		{
//			link*temp = current;
//			previous->next = previous->next->next;
//			current = current->next;
//			delete temp;
//			temp = NULL;
//		}
//		else
//		{
//			previous = current;
//			current = current->next;
//		}
//	}
//} lptr = top;
//cout << "Linkedlist state after removing even nodes : \n";
//while (lptr) {
//	cout << lptr->value<<endl;
//	lptr = lptr->next;
//}
//cout << endl;
//system("pause");
//}
