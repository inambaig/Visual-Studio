#include <stdio.h>
#include <iostream>


void main()
{
	char c[] = "GATE2011";
	char *p = c;
	printf("%s", p + p[3] - p[1]);
	system("pause");
}