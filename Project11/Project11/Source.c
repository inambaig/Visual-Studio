#include <stdio.h>

int main()
{
	int input= 123;
	int count = 0;
	printf("Please enter a number between 0 to 9999 : ");
	int result = scanf_s("Input a number : %d", &input);
	printf("The digits are as follows : \n");
	while (input > 0)
	{
		printf("%d ", input%10);
		input /= 10;
		count++;
	}
	printf("\nNumber of digits are : %d\n", count);



	system("pause");
	return 0;
}