#pragma once
#include "PQType.h"
template <class ItemType> class Scheduler : public PQType<ItemType>
{
public:
	Scheduler(int);
	int getNumJobs() const;
	void getCurrentJob(ItemType&);
	void setCurrentJob(ItemType&);
	void addJob(ItemType&);
	void removeJob(ItemType& j);
private:
	int numJobs;
	ItemType currentJob;
};