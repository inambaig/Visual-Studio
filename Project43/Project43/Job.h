#pragma once
#include <iostream>
using namespace std;

class Job{
public:   Job();
		  Job(int, int);
		  int getLength() const;
		  void decrementLength();
		  int getPriority() const;
		  friend ostream& operator<<(ostream& out, const Job& j);
		  bool operator<(Job otherJob);   bool operator>(Job otherJob);
		  bool operator==(Job otherJob);   bool operator<=(Job otherJob);

private:   int length;   int priority;
};
