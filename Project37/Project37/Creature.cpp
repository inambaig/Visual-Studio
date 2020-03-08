#include "Creature.h"


Creature::Creature()
{
	name = "";
	strength = 0;
}

Creature::Creature(string name, int strength)
{
	this->name = name;
	this->strength = strength;
}

void Creature::setName(string name)
{
	this->name = name;
}
string Creature::getName()
{
	return name;
}
void Creature::setStrength(int strength)
{
	this->strength = strength;
}
int Creature::getStrength()
{
	return strength;
}
void Creature::display()
{
	cout << endl;
	cout << "Name of Creature : " << name << endl;
	cout << "Strength of Creature : " << strength << endl;
}


Creature::~Creature()
{
}
