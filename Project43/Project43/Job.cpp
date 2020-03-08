#include "Job.h"
Job::Job()
{
	length = 0;
	priority = -19;
}
Job::Job(int length, int priority)
{
	this->length = length;
	this->priority = priority;
}
int Job::getLength() const
{
	return length;
}
void Job::decrementLength()
{
	length--;
}
int Job::getPriority() const
{
	return priority;
}
ostream& operator<<(ostream& out, const Job& j)
{
	out << "Length : " << j.length << endl;
	out << "Priority : " << j.priority << endl;
	return out;
}
bool Job::operator<(Job otherJob)
{
	if (this->priority < otherJob.priority)
		return true;
	else
		return false;
}
bool Job::operator>(Job otherJob)
{
	if (this->priority > otherJob.priority)
		return true;
	else
		return false;
}
bool Job::operator==(Job otherJob)
{
	if (this->priority == otherJob.priority)
		return true;
	else
		return false;
}
bool Job::operator<=(Job otherJob)
{
	if (this->priority <= otherJob.priority)
		return true;
	else
		return false;
}