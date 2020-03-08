#pragma once
#ifndef WINDOWS
#include "Creature.h"
class Orc : public Creature
{
	double malevolence;
public:
	Orc();
	Orc(string name, double malevolence);
	void setMalevolence(double);
	double getMalevolence();
	virtual void display();
	virtual ~Orc();
};
#endif
