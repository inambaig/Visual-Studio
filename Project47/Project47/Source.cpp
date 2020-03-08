#include <stdio.h>
int start(int argc, char **argv);

int main()
{
	char*argv = new char[];
	argv = "123";
	
	printf("argv = 123, argc = 2 :  %d\n", start(2, &argv));
	argv = "abc";
	printf("argv = abc, argc = 2 :  %d\n", start(2, &argv));
	argv = "-123";
	printf("argv = -123, argc = 2 :  %d\n", start(2, &argv));
	argv = "123";
	printf("argv = 123, argc = 4 :  %d\n", start(4, &argv));
	return 0;
}

int start(int argc, char **argv)
{
	if (argc != 2)
		return -1;
	else
	{
		int value = -987654321;
		char *argvv = *argv;

		sscanf_s(argvv, "%d", &value);

		if (value == -987654321)
		{
			return -2;
		}
		else if (value <= 0)
		{
			return-3;
		}
		else
			return value;

	}
}