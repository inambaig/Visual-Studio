#include <iostream>
#include <string>
using namespace std;

// This is function 7
double toCelsius(double fahrenheit)
{
	return (5 / 9)(fahrenheit-32);
}

// This is function 6 Kinetic Energy

double kineticEnergy(double mass, double velocity)
{
	return (1 / 2)*mass*velocity*velocity;
}

// This is function 5
double fallingDistance(double fallingTime)
{
	double g = 9.8;
	return (1 / 2)(g*fallingTime*fallingTime);
}

// This is function 4 Safest Driving area


int getNumAccidents(string name)
{
	cout << "Enter number of accidents reported last year in " << name << " area : ";
	int count = 0;
	cin >> count;
	if (count < 0)
	{
		cout << "Wrong input. Please re-enter";
		getNumAccidents(name);
		return 0;
	}
	return count;
}
// This is function 1 Markup

double calculateRetail(double wholeSaleCost, double markuppercent)
{
	return wholeSaleCost + (wholeSaleCost*markuppercent*0.01);
}




void main()
{

	system("pause");
}