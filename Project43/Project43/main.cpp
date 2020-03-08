#include <iostream>
#include <fstream>
#include "Scheduler.h"
#include "Job.h"
#include <Time.h>

void main()
{
	srand(time(NULL));

	int completed = 0;
	int incomplete = 0;
	for (int test = 0; test < 1000; test++)
	{

		Scheduler<Job> Sc(50);
		for (int i = 0; i < 50; i++)
		{
			int priority = ((rand() % 40) - 19);
			int length = ((rand() % 100) + 1);
			Job j1(length, priority);
			Sc.addJob(j1);
		}
		Job j1;
		Sc.Dequeue(j1);
		Sc.setCurrentJob(j1);


		int sum = 0;
		int i = 0;
		for (i = 0; i < 2700; i++)
		{
			sum += Sc.getNumJobs();

			j1.decrementLength();
			if (j1.getLength() <= 0)
			{
				Sc.Enqueue(j1);
				Sc.removeJob(j1);
				if (Sc.IsEmpty())
					break;
				Sc.Dequeue(j1);

				Sc.setCurrentJob(j1);
				if (Sc.getNumJobs() == 0)
					break;
			}
			if (i % 20 == 0)
			{
				int coin = rand() % 2;
				if (coin == 0)
					continue;
				else
				{
					Sc.Enqueue(j1);
					if (Sc.IsEmpty())
						break;
					Sc.Dequeue(j1);
					Sc.setCurrentJob(j1);
				}
			}
		}

		if (Sc.getNumJobs() <= 0)
		{
			completed++;
			cout << "Average number of jobs in the heap per cycle: " << sum / 2700 << endl;
			cout << "The scheduler completed all 50 jobs. " << endl;
			cout << "It took " << i << " cycles to complete them" << endl;
		}
		else
		{
			incomplete++;
			cout << "Average number of jobs in the heap per cycle: " << sum / 2700 << endl;
			cout << "The scheduler did not complete all 50 jobs. " << endl;
			cout << "Jobs Processed : " << (50 - Sc.getNumJobs()) << endl;
		}
	}

	cout << "Completed simulations: " << completed << endl;
	cout << "Incomplete simulations: " << incomplete << endl;
	
}



