#include "IntegerQueue.h"

int main()
{
	IntegerQueue A = newIntegerQueue();
	IntegerQueue B = newIntegerQueue();

	printf("%s\n", isEmpty(A) ? "true" : "false");
	printf("%s\n", isEmpty(B) ? "true" : "false");

	enqueue(A, 5);
	enqueue(A, 3);
	enqueue(A, 9);
	enqueue(A, 7);
	enqueue(A, 8);
	printf("%s\n", isEmpty(A) ? "true" : "false");
	printIntegerQueue(stdout, A);
	printf("\n");

	printf("%d\n", peek(A));
	dequeue(A);
	dequeue(A);
	dequeue(A);
	printf("%d\n", peek(A));
	printIntegerQueue(stdout, A);
	printf("\n");

	enqueue(B, 7);
	enqueue(B, 8);
	printIntegerQueue(stdout, B);
	printf("%s\n", equals(A, B) ? "true" : "false");
	printf("\n");

	enqueue(A, 12);
	enqueue(B, 13);
	printIntegerQueue(stdout, A);
	printIntegerQueue(stdout, B);
	printf("%s\n", equals(A, B) ? "true" : "false");
	printf("\n");

	dequeueAll(A);
	printIntegerQueue(stdout, A);
	printf("%s\n", isEmpty(A) ? "true" : "false");
	printf("\n");

	freeIntegerQueue(&A);
	freeIntegerQueue(&B);

	system("pause");
	return EXIT_SUCCESS;
}

