#include<stdlib.h>
#include<stdio.h>
#include"IntegerQueue.h"


typedef struct IntegerQueueObj{
	int* item;         // array of IntegerQueue items
	int physicalSize;  // current length of underlying array
	int numItems;      // number of items in this IntegerQueue
	int front;         // index of front element
	int back;          // index of back element
} IntegerQueueObj;


IntegerQueue newIntegerQueue(){
	IntegerQueue Q = malloc(sizeof(IntegerQueueObj));
	Q->item = calloc(1, sizeof(int));
	Q->physicalSize = 1;
	Q->numItems = 0;
	Q->front = 0;
	Q->back = -1;
	return Q;
}
void freeIntegerQueue(IntegerQueue* pQ)
{
	if (pQ != NULL && *pQ != NULL){
		free((*pQ)->item);
		free(*pQ);
		*pQ = NULL;
	}
}
int isEmpty(IntegerQueue Q){
	if (Q == NULL){
		fprintf(stderr, "IntegerQueue Error: isEmpty() called on NULL "\
			"IntegerQueue reference");
		exit(EXIT_FAILURE);
	}

	return (Q->numItems == 0);
}


int equals(IntegerQueue Q, IntegerQueue R){
	int i, n, m, eq = 0;
	if (Q == NULL || R == NULL){
		fprintf(stderr, "IntegerQueue Error: equals() called on NULL IntegerQueue "\
			"reference");
		exit(EXIT_FAILURE);
	}

	eq = ((Q->numItems) == (R->numItems));
	for (i = 0; eq && i<(Q->numItems); i++){
		n = ((Q->front) + i) % (Q->physicalSize);
		m = ((R->front) + i) % (R->physicalSize);
		eq = ((Q->item[n]) == (R->item[m]));
	}
	return eq;
}
void printIntegerQueue(FILE* out, IntegerQueue Q){
	int i, n = Q->numItems, m = Q->physicalSize;
	if (Q == NULL){
		fprintf(stderr, "IntegerQueue Error: printIntegerQueue() called on NULL "\
			"IntegerQueue reference");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i<n; i++){
		fprintf(out, "%d ", Q->item[((Q->front) + i) % m]);
	}
	fprintf(out, "\n");
}

void dequeueAll(IntegerQueue Q){
	if (Q == NULL){
		fprintf(stderr, "IntegerQueue Error: dequeueAll() called on NULL "\
			"IntegerQueue reference");
		exit(EXIT_FAILURE);
	}

	Q->numItems = 0;
	Q->front = 0;
	Q->back = -1;
}
int peek(IntegerQueue Q){
	if (Q == NULL){
		fprintf(stderr, "IntegerQueue Error: peek() called on NULL "\
			"IntegerQueue reference");
		exit(EXIT_FAILURE);
	}
	if ((Q->numItems) == 0){
		fprintf(stderr, "IntegerQueue Error: peek() called on empty "\
			"IntegerQueue");
		exit(EXIT_FAILURE);
	}

	return Q->item[Q->front];
}
int dequeue(IntegerQueue Q){
	int x;
	if (Q == NULL){
		fprintf(stderr, "IntegerQueue Error: dequeue() called on NULL "\
			"IntegerQueue reference");
		exit(EXIT_FAILURE);
	}
	if ((Q->numItems) == 0){
		fprintf(stderr, "IntegerQueue Error: dequeue() called on empty "\
			"IntegerQueue");
		exit(EXIT_FAILURE);
	}

	x = Q->item[Q->front];
	Q->front = ((Q->front) + 1) % (Q->physicalSize);
	(Q->numItems)--;
	return x;
}
void doubleItemArray(IntegerQueue Q){
	int i, n = Q->numItems, m = Q->physicalSize;
	int* newArray;
	int* oldArray = Q->item;
	newArray = calloc(2 * m, sizeof(int));
	for (i = 0; i<n; i++){
		newArray[i] = oldArray[((Q->front) + i) % m];
	}
	Q->item = newArray;
	Q->physicalSize = 2 * m;
	Q->front = 0;
	Q->back = n - 1;
	free(oldArray);
}
void enqueue(IntegerQueue Q, int x){
	if (Q == NULL){
		fprintf(stderr, "IntegerQueue Error: enqueue() called on NULL "\
			"IntegerQueue reference");
		exit(EXIT_FAILURE);
	}

	if ((Q->numItems) == (Q->physicalSize)){
		doubleItemArray(Q);
	}
	Q->back = ((Q->back) + 1) % (Q->physicalSize);
	Q->item[Q->back] = x;
	(Q->numItems)++;
}