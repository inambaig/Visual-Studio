#include "Orc.h"


Orc::Orc()
{
	setName("");
	setMalevolence(0.0);
}
Orc::Orc(string name, double malevolence)
{
	setName(name);
	setMalevolence(malevolence);
}
void Orc::setMalevolence(double malevolence)
{
	this->malevolence = malevolence;
}
double Orc::getMalevolence()
{
	return this->malevolence;
}
void Orc::display()
{
	cout << endl;
	cout << "Name of Orc : " << getName() << endl;
	cout << "Malevolence of Orc : " << getMalevolence() << endl;
}

Orc::~Orc()
{
}
