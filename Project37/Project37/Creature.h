#pragma once
#ifndef WINDOWS
#include <iostream>
#include <string>
using namespace std;
class Creature
{
	string name;
	int strength;
public:
	Creature();
	Creature(string name, int strength);
	void setName(string);
	string getName();
	void setStrength(int);
	int getStrength();
	virtual void display();
	virtual ~Creature();
};
#endif

