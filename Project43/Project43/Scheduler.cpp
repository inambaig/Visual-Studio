#include "Scheduler.h"
#include "Job.h"
typedef Job ItemType;


Scheduler<Job>::Scheduler(int queueSize) : PQType(queueSize)
{
	this->numJobs = 0;
}
int Scheduler<Job>::getNumJobs() const
{
	return numJobs;
}
void Scheduler<Job>::getCurrentJob(ItemType&j)
{
	j = currentJob;
}
void Scheduler<Job>::setCurrentJob(ItemType& currentJob)
{
	this->currentJob = currentJob;
}
void Scheduler<Job>::addJob(ItemType& newJob)
{
	numJobs++;
	Enqueue(newJob);
}
void Scheduler<Job>::removeJob(ItemType& j)
{
	numJobs--;
	Dequeue(j);
}

