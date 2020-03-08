#include <iostream>
#include <stdio.h>
using namespace std;
int start(int argc, char **argv);

int main()
{
	char**argv = new char*[3];
	printf("argv = 123, argc = 2 :  %d\n", start(2, argv));
	system("pause");
	return 0;
}

int start(int argc, char **argv)
{
	if (argc != 2)
		return -1;
	else
	{
		if (*(argv[1])>=48 && *(argv[1])<=57)
		{
			return -2;
		}
		else if (true)
		{
			return-3;
		}
		else
			return -4;

	}
}