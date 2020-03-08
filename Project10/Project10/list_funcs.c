#include<stdio.h>
#include<stdlib.h>
#include "list.h";
rider_st *create_new_rider(int id, char *first_name, char *last_name, double ave_rating, double distance)
{
	rider_st *newrider = malloc(sizeof(rider_st));
	newrider->ID = id;
	newrider->first_name = first_name;
	newrider->last_name = last_name;
	newrider->ave_rating = ave_rating;
	newrider->distance = distance; 
	newrider->next = NULL;
	
	return newrider;
}
void front_insert(rider_st **list_head, rider_st *to_be_inserted)
{
	if (*list_head == NULL)
	{
		*list_head = to_be_inserted;
	}
	else
	{
		to_be_inserted->next = *list_head;
		*list_head = to_be_inserted;
	}
}
void end_insert(rider_st **ptr_to_list_head, rider_st *to_be_inserted)
{
	rider_st *temp = *ptr_to_list_head;
	if (*ptr_to_list_head == NULL)
	{
		*ptr_to_list_head = to_be_inserted;
		return;
	}
	while (temp->next!=NULL)
	{
		temp = (temp)->next;
	}
	(temp)->next = to_be_inserted;
}
void ordered_insert(rider_st **ptr_to_list_head, rider_st *to_be_inserted)
{
	rider_st* temp;
	/* Special case for the head end */
	if (*ptr_to_list_head == NULL)
	{
		*ptr_to_list_head = to_be_inserted;
		return;
	}
	if (*ptr_to_list_head != NULL && (*ptr_to_list_head)->distance >= to_be_inserted->distance)
	{
		to_be_inserted->next = *ptr_to_list_head;
		*ptr_to_list_head = to_be_inserted;
	}
	else
	{
		/* Locate the node before the point of insertion */
		temp = *ptr_to_list_head;
		while (temp->next != NULL && temp->next->distance < to_be_inserted->distance)
		{
			temp = temp->next;
		}
		to_be_inserted->next = temp->next;
		temp->next = to_be_inserted;
	}
}
void empty(rider_st **list_head)
{
	rider_st* current = NULL;
	rider_st* next;
	if (*list_head == NULL)
		return;
	current = *list_head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	/* deref head_ref to affect the real head back in the caller. */
	*list_head = NULL;
}
void delete(rider_st **ptr_to_list_head, rider_st *to_be_deleted)
{
	rider_st* temp = *ptr_to_list_head, *temp2 = NULL;
	if (*ptr_to_list_head == NULL)
		return;

	// If head node itself holds the Id 
	if (temp != NULL && temp->ID == to_be_deleted->ID)
	{
		*ptr_to_list_head = temp->next;   // Changed head 
		free(temp);               // free old head 
		temp = *ptr_to_list_head;         // Change Temp 
		return;
	}

	// Delete occurrences other than head 
	while (temp->next != NULL)
	{
		// Search for the key to be deleted, keep track of the 
		// previous node as we need to change 'prev->next' 
		
		if (temp->next->ID == to_be_deleted->ID)
		{
			rider_st*del = temp->next;
			temp->next = temp->next->next;
			free(del);
		}
	}
}
rider_st find_next_distance_rider(rider_st *list_head, double min_distance)
{
	rider_st* temp = list_head;
	rider_st* temp2 = NULL;
	if (list_head == NULL)
		return;
	double dist_store = temp->distance;
	temp2 = temp;
	while (temp->next != NULL && dist_store <= min_distance)
	{
		temp = temp->next;
		dist_store = temp->distance;
		temp2 = temp;
	}
	if (temp2->distance <= min_distance)
		return *temp2;
	temp = list_head;
	while (temp != NULL)
	{
		if (temp->distance > min_distance && temp->distance < dist_store && temp->distance < dist_store)
		{
			dist_store = temp->distance;
			temp2 = temp;
		}
		temp = temp->next;
	}
	return *temp2;
}