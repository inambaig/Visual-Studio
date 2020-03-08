#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>

using namespace std;

struct Movie{

	Movie();

	string title;
	double runTime;
	int expectedYield;
	char roomID;
	int capacity;
	int available;
};

#endif // MOVIE_H