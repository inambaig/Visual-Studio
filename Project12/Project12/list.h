#include <stdio.h>
#include <stdlib.h>


typedef struct NodeObj {

	int value;

	struct NodeObj *prev;

	struct NodeObj *next;

} NodeObj;

// This function will create a new node and returns that node.
// If the function fails to create the node due to any reason then it will return NULL.
NodeObj *create_new_node(int id);
// This function will insert the node (to_be_inserted, passed as parameter) 
// at the end of linked list with head list_head.
void insert(NodeObj **list_head, NodeObj *to_be_inserted);
// This function will insert the node (to_be_inserted, passed as parameter) 
// while maintaining the increasing order of linked list with head list_head.
void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted);
// This function will delete all the nodes from the linked list and free all the memory associated to it
void delete_all(NodeObj *list_head);
// This function will delete the node (to_be_deleted, passed as parameter) for the linked list list_head
void delete(NodeObj **list_head, NodeObj *to_be_deleted);


