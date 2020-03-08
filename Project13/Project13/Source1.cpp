#include<iostream> 
using namespace std;
int main()
{
	int current, previous;
	int lptr;
	int nextAvailable = 1;
	const int ArraySize = 128;
	int value[ArraySize] = { 0 };
	int link[ArraySize] = { 0 };
	int ivalue;
	cout << "Input next value, -1 to terminate > " << flush;
	cin >> ivalue;
	while (ivalue != -1)
	{
		lptr = nextAvailable++;
		value[lptr] = ivalue;
		current = link[0];
		previous = 0;

		if (nextAvailable == 2)
		{
			link[0] = 1;
		}
		else if (value[link[0]] >= ivalue)
		{
			link[lptr] = link[0];
			link[0] = lptr;
		}
		else
		{
			current = link[0];
			bool inserted = false;
			while (link[current] != 0)
			{
				if (value[current] < ivalue && value[link[current]] >= ivalue)
				{
					inserted = true;
					link[lptr] = link[current];
					link[current] = lptr;
				}
				previous = current;
				current = link[current];
			}
			if (!inserted)
			{
				if (value[current] > ivalue)
				{
					if (previous == 0)
					{
						link[lptr] = current;
						link[0] = lptr;
					}
					else
					{
						link[lptr] = current;
						link[previous] = lptr;
					}
				}
				else
					link[current] = lptr;
			}
		}
		cout << "Input next value, -1 to terminate > " << flush; cin >> ivalue;
	}
	lptr = link[0];
	while (lptr) {
		cout << value[lptr] << endl;
		lptr = link[lptr];
	}
	current = link[0];
	previous = 0;
	while (current != 0) {
			if (link[current] == 0)
			{
				if (value[current] % 2 == 0)
				{
					current = 0;
					break;
				}
			}
			if (previous == 0)
			{
				if (value[current] % 2 == 0)
				{
					int temp = current;
					current = link[current];
					value[temp] = 0;
					link[temp] = 0;
				}
				else
				{
					previous = current;
					current = link[current];
				}
			}
			else
			{
				if (value[current] % 2 == 0)
				{
					int temp = current;
					link[previous] = link[link[previous]];
					current = link[current];
					value[temp] = 0;
					link[temp] = 0;
				}
				else
				{
					previous = current;
					current = link[current];
				}
			}
		}
		lptr = link[0];
		cout << endl;
		while (lptr) {
			cout << value[lptr] << endl; lptr = link[lptr];
		}
		system("pause");
	}

