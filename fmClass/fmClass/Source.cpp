#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
	double length;
	double width, height;

	cout << "Length : ";
	cin >> length;
	cout << "Width : ";
	cin >> width;
	cout << "Height : ";
	cin >> height;

	double volume = length * width*height;
	double area = length * width;
	double areaRoom1 = area / 2;
	double areaRoom2 = area / 4;
	double areaRoom3 = area / 4;

	double requiredLabourers = volume / 575;//10.5
	int requiredLabourersInt = ceil(requiredLabourers);//11

	double hoursRequired = 2.5*area;
	double cost = hoursRequired * requiredLabourersInt*  10;

	cout << fixed;
	cout << setprecision(2);

	cout << "The volume of the building: " << volume << " Cubic feet" << endl;
	cout << "Area of the building: " << area << " Square feet" << endl;
	cout << "Area Room 1 : " << areaRoom1 << " Square feet" << endl;
	cout << "Area Room 2 : " << areaRoom2 << " Square feet" << endl;
	cout << "Area Room 3 : " << areaRoom3 << " Square feet" << endl;
	cout << "# laborers required: " << requiredLabourersInt << "  ( actual is " << requiredLabourers << " rounded off to " << requiredLabourersInt << ") " << endl;
	cout << "# Hours to build: " << hoursRequired << endl;
	cout << "Cost to build: $" << cost << endl;
	system("pause");
}