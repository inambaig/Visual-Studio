#include "stdio.h"
#include "math.h"
#define MAXCHAR 100
typedef struct {
	char name[MAXCHAR];
	double longitude;
	double latitude;
}CITY;


int main()
{
	CITY cityArray[80];
	int cityCounter = 0;
	FILE *fp;

	fp = fopen("longlat.txt", "r");
	if (fp == NULL){
		printf("Could not open file longlat.txt");
		return 0;
	}

	for (int i = 0; i < 77; i++)
	{
		fscanf(fp, "%s %lf %lf", &(cityArray[i].name), &(cityArray[i].latitude), &(cityArray[i].longitude));
	}
	fclose(fp);

	fp = fopen("path.txt", "r");
	double veryStrong, terriblyStrong, latitude, longitude;
	int date, hours;
	char month[15];
	for (int x = 0; x < 8; x++)
	{
		fscanf(fp, "%lf %lf %lf %lf %d %s %d", &veryStrong, &terriblyStrong, &latitude, &longitude, &hours, &month, &date);
		for (int i = 0; i < 77; i++)
		{
			int isStrong = 0;
			double latDiff = cityArray[i].latitude - latitude;
			double longDiff = cityArray[i].longitude - longitude;
			latDiff = latDiff*latDiff;
			longDiff = longDiff*longDiff;
			double result = latDiff + longDiff;
			result = sqrt(result);
			if (result <= terriblyStrong || result <= veryStrong)
				isStrong = 1;

			if (isStrong == 1)
			{
				printf("%s %d, %d: %s strong wind loop\n", month, date, hours, cityArray[i].name);
			}
		}
	}
	return 0;
}