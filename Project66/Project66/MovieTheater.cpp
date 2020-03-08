#include "MovieTheater.h"

MovieTheater::MovieTheater(){
	numMovies = GetNumMovies();
	movies = new Movie[numMovies];
}

MovieTheater::~MovieTheater(){
	delete[] movies;
}


int MovieTheater::GetNumMovies(){
	int num;
	ifstream infile;
	infile.open("movies.txt");
	if (!infile){
		cout << "Cannot Open File movies.txt" << endl;
		return 0;
	}
	else{
		infile >> num;
		infile.close();
		return num;
	}
}

void MovieTheater::PrintMovies(){

	cout << setw(40) << "Playing Now" << endl << endl;
	cout << setw(30) << std::left << "FILM" << setw(15) << "TOTAL SEATS" << setw(15) << "AVAIL. SEATS" << setw(15) << "RUNTIME" << setw(15) << "EXPECTED YIELD" << setw(15) << "ROOM" << endl;
	for (int i = 0; i<numMovies; i++){
		cout << setw(30) << std::left << movies[i].title
			<< setw(15) << movies[i].capacity
			<< setw(15) << movies[i].available
			<< setw(15) << movies[i].runTime
			<< setw(15) << ConvertYieldToString(movies[i].expectedYield)
			<< setw(15) << movies[i].roomID << endl;
	}
	cout << endl << endl;
}

string MovieTheater::ConvertYieldToString(int yield){
	if (yield == 2)
		return "high";
	else if (yield == 1)
		return "medium";
	else if (yield == 0)
		return "low";
	else
		return "error";
}

void MovieTheater::sortMovies()
{
	for (int i = 0; i < numMovies; i++){
		for (int j = i; j < numMovies; j++){
			if (movies[i].expectedYield < movies[j].expectedYield)
			{
				Movie m = movies[i];
				movies[i] = movies[j];
				movies[j] = m;
			}
		}
	}
}
