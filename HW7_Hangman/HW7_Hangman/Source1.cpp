#include<iostream>
#include<cmath> 
using namespace std;

float volume_sphare(float d)
{
	float dia = d*d;
	float v = (1 / 6)*(3.14)*dia*d;
	return v;
}
float Area_of_sphare(float radius)
{
	radius = radius / 2;
	return 4 * 3.14 * (radius*radius);
}
float volume_cone(float dia, float h)
{
	float r = dia / 2;
	return 3.14*r*r*(h / 3);
}
float Area_of_cone(float dia, float h)
{
	float r = dia / 2;
	return 3.14*r*(r + sqrt((r*r) + (h*h)));
}
float volume_cylinder(float rad, float h)
{
	return 3.14*rad*rad*h;
}
float Area_of_cylinder(float dia, float h)
{
	float	rad = dia / 2;
	return (2 * 3.14*rad*h) + (2 * 3.14*rad*rad);
}

float volume_donuts(float R, float r)
{
	return 2 * 3.14*3.14*R*r*r;
}





int main()
{

	float ap, pi, co, don;
	cout << "How many apple you are going to eat? ";
	cin >> ap;
	cout << "How many  pizza you are going to eat? ";
	cin >> pi;
	cout << "How many cone you are going to eat? ";
	cin >> co;
	cout << "How many donuts you are going to eat? ";
	cin >> don;
	float t_Volume = (ap*volume_sphare(3)) + (pi*volume_cylinder(12, 0.5)) + (co*volume_cone(2, 5)) + (don*volume_donuts(1.5, .5)) + (don*volume_sphare(2.5));
	cout << "The Total Amount of Volume you are going to eat: " << t_Volume << endl;

	system("pause");
	return 0;
}



