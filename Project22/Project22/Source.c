#include <stdio.h>
typedef struct
{
	int sid;
	int tel;
}
STUDENTX;

void main()
{
	STUDENTX sx[5];
	STUDENTX *ptr[5];
	sx[0].sid = rand() % 100;
	sx[0].tel = rand() % 100000;
	ptr[0] = &sx[0];

	sx[1].sid = rand() % 100;
	sx[1].tel = rand() % 100000;
	ptr[1] = &sx[1];

	sx[2].sid = rand() % 100;
	sx[2].tel = rand() % 100000;
	ptr[2] = &sx[2];

	sx[3].sid = rand() % 100;
	sx[3].tel = rand() % 100000;
	ptr[3] = &sx[3];

	sx[4].sid = rand() % 100;
	sx[4].tel = rand() % 100000;
	ptr[4] = &sx[4];



	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ptr[j]->tel > ptr[j + 1]->tel)
			{
				STUDENTX* t = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = t;
			}
		}
	}
}
