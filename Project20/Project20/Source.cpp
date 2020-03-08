#include <stdio.h>
#include <stdlib.h>

void g(int x, int y, int*p, int**q)
{
	int t;
	t = x;
	x = y;
	y = t;
	t = *p;
	*p = **q;
	**q = y;
	*q = p;
}

int main(void)
{
	int a = 5, b = 20, c = 30, d = 100;
	int *pd, *pc;
	pc = &c;
	pd = &d;
	g(a, b, pd, &pc);
	printf("a = %d, b = %d, c = %d, d = %d, *pc = %d, *pd = %d\n", a, b, c, d, *pc, *pd);
	system("pause");
}