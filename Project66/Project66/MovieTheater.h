#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H
#include "Movie.h"
#include <fstream>
#include <iomanip>

struct MovieTheater
{
	//member functions
	MovieTheater(); //constructor
	~MovieTheater(); //destructor
	void    PrintMovies();
	int     GetNumMovies();
	string  ConvertYieldToString(int yield);
	void sortMovies();

	//member variables
	int numMovies;
	Movie *movies;
};

#endif // MOVIETHEATER_H
