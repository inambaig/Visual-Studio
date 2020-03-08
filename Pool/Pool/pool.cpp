#include <iostream>
using namespace std;
int main()
{
	double length, width, depth;
	cout << "Enter length of pool : ";
	cin >> length;
	cout << "Enter width of pool : ";
	cin >> width;
	cout << "Enter depth of pool : ";
	cin >> depth;
	cout << "Length = " << length << endl;
	cout << "Width = " << width << endl;
	cout << "Depth = " << depth << endl;
	double volume = length*width*depth;
	double volumeOfWater = length*width*(depth - 0.25);
	double cost = (volumeOfWater*0.77) + 100;
	if (depth < 0.25)
		cout << "Water can not be filled in it.\n";
	else
	{
		cout << "Pool Volume is : " << volume << endl;
		cout << "Volume of water  needed : " << volumeOfWater << endl;
		cout << "Final cost of water : " << cost << endl;
	}

	cout << "Program is built by Ziwei Liu" << endl;
	system("pause");
	return 0;
}