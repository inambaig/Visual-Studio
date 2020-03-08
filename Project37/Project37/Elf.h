#pragma once
#ifndef WINDOWS
#include "Creature.h"
class Elf : public Creature
{
	int ability;
public:
	Elf();
	Elf(string, int);
	void setAbility(int);
	int getAbility();
	virtual void display();
	virtual ~Elf();
};
#endif