//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void fsort(float r[], int x)
//{
//	for (int i = 0; i < x; i++)
//	{
//		for (int j = i+1; j < x; j++)
//		{
//			if (r[i] > r[j])
//			{
//				float a = r[i];
//				r[i] = r[j];
//				r[j] = a;
//			}
//		}
//	}
//}
//int main()
//{
//	//int RAND_MAX = 214748;
//	srand(time(0));
//	const int n_buses = 40;
//	float r[40];
//	int i = 0;
//	for (i = 0; i< n_buses; i++) 
//		r[i] = (float)(599)* ((float)rand() / (float)RAND_MAX);
//
//	fsort(r, 40);
//	float waitTime[100] = { 0.0 };
//	int k = 0;
//	for (k = 0; k < 100; k++)
//	{
//		float your_bus_stop_arrival_time = (float)(599)* ((float)rand() / (float)RAND_MAX);
//
//		for (i = 0; i < n_buses; i++)
//		{
//			if (r[i] - your_bus_stop_arrival_time >= 0.0)
//			{
//				waitTime[k] = r[i] - your_bus_stop_arrival_time;
//				i = 50;
//			}
//		}
//	}
//
//
//	// Histogram
//	fsort(waitTime, 100);
//
//
//	printf("Wait Time Sorted Chart\n\n");
//	for (k = 0; k < 100; k++)
//		printf("Wait_Time[%d] = %f\n", k, waitTime[k]);
//	int j = 0;
//	k = 0;
//	float at = 5.0;
//	int hist[20];
//	for (i = 0; i < 20; i++)
//	{
//		hist[i] = 0;
//	}
//	for (j = 0; j<100; j++)
//	{
//			hist[k]++; 
//		if (waitTime[j] >= ((k + 1)*at))
//		{
//			k++;
//		}
//	}
//
//	printf("\n\nHistogram\n\n");
//	for (i = 0; i < 19; i++)
//	{
//		printf("[%f - %f]\tis %d\n", at*i, at*(i+1), hist[i]);
//	}
//	return 0;
//}