#include "list.h"

// This function will create a new node and returns that node.
// If the function fails to create the node due to any reason then it will return NULL.
NodeObj *create_new_node(int id)

{
	// Below statement will create a Null pointer
	NodeObj * temp = NULL;
	// assign heap address
	temp = malloc(sizeof(NodeObj));
	// Below function will assign the id passed as parameter to the value of node
	temp->value = id;
	// Below statement will set next of the node to NULL
	temp->next = NULL;
	// Below statement will set previous of node to NULL.
	temp->prev = NULL;
	// Below statement will return the temp;
	return temp;
}

// This function will insert the node (to_be_inserted, passed as parameter) 
// at the end of linked list with head list_head.
void insert(NodeObj **list_head, NodeObj *to_be_inserted)

{
	NodeObj * temp = *list_head;
	// Below statement will check if the head passed as parameter is NULL.
	// It will execute if the head is NULL
	if (temp == NULL)
	{
		// If the head is NUll then the node to be inserted will actually be the head
		*list_head = to_be_inserted;
	}
	else
	{
		// This loop will execute till temp reach to the end of linked list
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		// Below 3 statements will insert the node between temp and temp->next.
		// On this case, temp is the last node so it is inserted between temp and NULL.
		to_be_inserted->next = temp->next;
		to_be_inserted->prev = temp;
		temp->next = to_be_inserted;

	}

}
// This function will delete the node (to_be_deleted, passed as parameter) for the linked list list_head
void delete(NodeObj **list_head, NodeObj *to_be_deleted)
{
	// This will check if any of the pointers passed as parameter are NULL. 
	// So if any pointer is NULL the below if statement will execute to give an error message
	if ((to_be_deleted == NULL) || ((*list_head) == NULL))
	{
		fprintf(stderr, "bad input, null pointer not an acceptable input value\n");
	}
	else
	{
		// Below if statement will check if the node to be deleted has a prev element.
		// So in other words it will check if it is not the first node.
		// If its not a first node then it will skip this node from the list and 
		// connect the previos node directly to the next node
		if (to_be_deleted->prev != NULL)
			to_be_deleted->prev->next = to_be_deleted->next;
		// Below if statement will check if the node to be deleted has a next element.
		// So in other words it will check if it is not the last node.
		// If its not a last node then it will skip this node from the list and 
		// connect the previos node directly to the next node
		if (to_be_deleted->next != NULL)
			to_be_deleted->next->prev = to_be_deleted->prev;
		// below statement will free the memory allocated to this node
		free(to_be_deleted);

	}

}
// This function will insert the node (to_be_inserted, passed as parameter) 
// while maintaining the increasing order of linked list with head list_head.
void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted)
{
	NodeObj * temp = *list_head;
	// Below statement will check if the head passed as parameter is NULL.
	// It will execute if the head is NULL
	if (temp == NULL)
	{
		// If the head is NUll then the node to be inserted will actually be the head
		*list_head = to_be_inserted;
	}
	else
	{

		// This loop will execute till temp reach to the end of linked list
		while (temp->next != NULL)
		{

			// This statement will chck if the current node (temp) value is less than or equal to to_be_inserted 
			// and the node next to temp is greater than or equal to to_be_inserted 
			// So it will break the loop because temp is at correct position at this time
			if (temp->value <= to_be_inserted->value && temp->next->value >= to_be_inserted->value)
			{
				break;
			}
			else
				temp = temp->next;
		}

		// Below 3 statements will insert the node between temp and temp->next.
		// On this case, temp is the last node so it is inserted between temp and NULL.
		to_be_inserted->next = temp->next;
		to_be_inserted->prev = temp;
		temp->next = to_be_inserted;
	}
}

// This function will delete all the nodes from the linked list and free all the memory associated to it
void delete_all(NodeObj *list_head)
{
	// Below statement will check if the head passed as parameter is NULL.
	// It will execute if the head is NULL
	if (list_head == NULL)
	{
		fprintf(stderr, "bad input, null pointer not an acceptable input value\n");
	}
	else
	{
		NodeObj *temp = list_head;
		// Following loop will execute till the end of linked list
		while (list_head != NULL)
		{
			// This will save the current list head to temp and the statement next to it will move the head to the next node, because 
			// we are interested in deleting the current head
			temp = list_head;
			list_head = list_head->next;
			list_head->prev = NULL;
			// This will 
			free(temp);
		}
	}
}