#include "Orc.h"
#include "Elf.h"
#include "Creature.h"
#include <conio.h>

int main()
{
	Creature*ptrArray[6];
	ptrArray[0] = new Creature("First Creature", 5);
	ptrArray[1] = new Creature("Second Creature", 10);
	ptrArray[2] = new Orc("First Orc", 2.0);
	ptrArray[3] = new Orc("Second Orc", 4.0);
	ptrArray[4] = new Elf("First Elf", 8);
	ptrArray[5] = new Elf("Second Elf", 12);

	for (int i = 0; i < 6; i++)
	{
		ptrArray[i]->display();
	}

	cout << endl << "Press any key to continue " << endl;
	_getch();
}