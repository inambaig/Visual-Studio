/*******************************************************************************
AUTHOR SECTION

ENGR 200.xx                                               DATE: mm/dd/yyyy

PROGRAM: #                               Author:
********************************************************************************
PROGRAM DESCRIPTION

DESCRIPTION OF VARIABLES
NAME         |  TYPE    | DESCRIPTION
-----------------------------------------------------------------------------

*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
/* Main function */
int main(void)
{
	/* Declare variables */
	FILE *fp;
	int c = 0;
	char cityname[21];
	int windSpeed[5][12];
	int averageForEachYear[5];
	int minimumSpeed = 100;
	int maximumSpeed = 0;
	int temp = 0; int yearMonthTrack[4];
	
	/* Print headings */
	printf("********************************************");
	printf("\n ");

	/* Input values */
	FILE* reader = fopen("U:\ENGR 200\wind.txt", "r");
	FILE* writer = fopen("U:\ENGR 200\wind_report.txt", "w");

	if (reader == NULL)
		printf("Wind file is not found\n");
	if (writer == NULL)
		printf("Wind_Report.txt is not found\n");


	while (1) {
		fscanf(reader, "%c", &cityname[c]);
		c++;
		if (c==21)
		{
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		temp = fgetc(fp);
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			fscanf(reader, "%d", &windSpeed[i][j]);
		}
	}


	/* Compute */

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			averageForEachYear[i] += windSpeed[i][j];
			if (windSpeed[i][j]>maximumSpeed)
			{
				maximumSpeed = windSpeed[i][j];
				yearMonthTrack[0] = i;
				yearMonthTrack[1] = j;
			}
				
			if (windSpeed[i][j] < minimumSpeed)
			{
				minimumSpeed = windSpeed[i][j];
				yearMonthTrack[2] = i;
				yearMonthTrack[3] = j;
			}
				
		}
		averageForEachYear[i] = averageForEachYear[i] / 12;
	}

	/* Print output values */
	printf("\n\nRESULTS");
	printf("\n********************************************\n\n\n");
	for (int i = 0; i < 21;i++)
	printf("\t%c",cityname[i]);
	printf("\n\t\tYear1\tYear2\tYear3\tYear4\tYear5\n\n");
	
		for (int j = 0; j < 12; j++)
		{
			printf("month $d\t$d\t$d\t$d\t$d\t$d\n", 0 + j, windSpeed[0][j], windSpeed[1][j], windSpeed[2][j], windSpeed[3][j], windSpeed[4][j]);
		}
		printf("\n\nAverage:");
		for (int i = 0; i < 5; i++)
		{
			printf("\t%d", averageForEachYear[i]);
		}
	printf("\n\t\tYear1\tYear2\tYear3\tYear4\tYear5\n\n");
	fprintf(writer, "Minimum speed is %d mph in month %d, year %d\n",minimumSpeed,yearMonthTrack[3], yearMonthTrack[2]);
	fprintf(writer, "Maximum speed is %d mph in month %d, year %d", maximumSpeed, yearMonthTrack[1], yearMonthTrack[0]);
	/* Exit the program */
	return 0;
}
/******************************************************************************/