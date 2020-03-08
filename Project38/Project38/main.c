/*********************************************************************
*               SEGGER MICROCONTROLLER GmbH & Co. KG                 *
*       Solutions for real time microcontroller applications         *
**********************************************************************
*                                                                    *
*       (c) 2014 - 2016  SEGGER Microcontroller GmbH & Co. KG        *
*                                                                    *
*       www.segger.com     Support: support@segger.com               *
*                                                                    *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start
*/

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/



extern float computeArea(int *v1, int *v2, int shape);
extern int numTimesAppears(char *, char);

void main(void) {
	int i;
	char mystring[100] = "Yusuf Ozturk";
	char ch;
	float area;
	int  length, height, diameter, base;

	int count;

	base = 25;
	length = 25;
	height = 10;
	diameter = 5;

	area = computeArea(&base, &height, 1);
	printf("\nThe area of the triangle is %f", area);

	area = computeArea(&diameter, &diameter, 3);
		printf("\nThe area of a circle is %f", area);


	ch = 'u';
	count = numTimesAppears(mystring, ch);
	printf("\n Number of times %c appears in string is %d", ch, count);
	system("pause");
}

float  computeArea(int *v1, int *v2, int shape)
{
	float areaComputed = 0.0;
	// this if will execute if shape = 1
	if (shape == 1)
	{
		// 1 triangle
		// calculating area of triangle
		areaComputed = (double)((*v1)*(*v2)) / (double)2;
	}
	// this if will execute if shape = 2
	else if (shape == 2)
	{
		// 2 square
		// calculating area of square
		areaComputed = ((*v1)*(*v2));
	}
	// this if will execute if shape = 3
	else if (shape == 3)
	{
		// 3 circle
		// calculating radius
		float radius = (float) (((double)*v1) / (double)2);
		// calculating area of circle
		areaComputed = ((double)22/7) * (radius*radius);
	}
	return(areaComputed);

}
int numTimesAppears(char  *mystring, char ch)
{
	int i;
	int count = 0;
	// stores the length of string passed as parameter
	int length = strlen(mystring);

	// traverse till end of string
	for (i = 0;i<length;i++)
	{
		// it will execute if the character at current index matches the passed parameter

		if (mystring[i] == ch)
			// incerements the count
			count++;
	}
	// returns the count
	return(count);
}






/*************************** End of file ****************************/