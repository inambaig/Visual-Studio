#include "Elf.h"


Elf::Elf()
{
	setName("");
	setAbility(0);
}
Elf::Elf(string name, int ability)
{
	setName(name);
	setAbility(ability);
}
void Elf::setAbility(int ability)
{
	this->ability = ability;
}
int Elf::getAbility()
{
	return ability;
}
void Elf::display()
{
	cout << endl;
	cout << "Name of Elf : " << getName() << endl;
	cout << "Ability of Elf : " << getAbility() << endl;
}
Elf::~Elf()
{
}
