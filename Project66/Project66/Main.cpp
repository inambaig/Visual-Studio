#include <iostream>
#include <fstream>
//#include "Movie.h"
#include "MovieTheater.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

void    PressKeyToContinue();
void    LoadMovies(Movie movies[]);
void    LoadRooms(Movie movies[], int size);
void    SellTickets(int numTickets, Movie movies[], int size);
void    Operate(MovieTheater cinema);
void    PrintPrice(int numTickets);

void     GetTicketNumber(int &tickets);
int     SelectMovie(Movie movies[], int size);
int     GetMovieIndex(Movie movies[], int size, string movie);
void sortMovies(Movie*&movies, int numMovies);
int main(){

	MovieTheater cinema;
	LoadMovies(cinema.movies);
	LoadRooms(cinema.movies, cinema.numMovies);
	sortMovies(cinema.movies, cinema.numMovies);
	Operate(cinema);
	return 0;
}

void Operate(MovieTheater cinema){

	int numTickets = 0;
	cinema.sortMovies();
	
	while (true){

		cinema.PrintMovies();
		GetTicketNumber(numTickets);
		SellTickets(numTickets, cinema.movies, cinema.numMovies);
		numTickets = 0;
		system("CLS");
	}
}

void PressKeyToContinue(){
	string key;
	cout << "Press any key to continue:";
	cin >> key;
}

void SellTickets(int numTickets, Movie movies[], int size){
	int movieIndex = -1;
	movieIndex = SelectMovie(movies, size);

	if (movieIndex != -1 && movies[movieIndex].available >= numTickets){
		movies[movieIndex].available = movies[movieIndex].available - numTickets;
		PrintPrice(numTickets);
	}
	else if (movieIndex != -1 && movies[movieIndex].available < numTickets){
		cout << "No Room Available" << endl;
		PressKeyToContinue();
	}
}

void PrintPrice(int numTickets){
	double price = 7.25;
	cout << "Price:" << price*numTickets << endl << endl;
	PressKeyToContinue();
}

void GetTicketNumber(int &tickets){
	while (tickets == 0){
		cout << "How many tickets?:";
		cin >> tickets;
		cout << endl;
		if (tickets<0 || tickets>390){
			cout << "Invalid Ticket Number, must be greater than 0 and smaller than 391" << endl;
			tickets = 0;
		}
	}
}

int SelectMovie(Movie movies[], int size){
	string movie = "";
	int movieIndex = -1;
	while (movie == ""){
		cout << "Enter movie name or \"cancel\" :";
		cin >> movie;

		if (movie == "cancel"){
			cout << "Ticket Purchase Canceled" << endl;
			PressKeyToContinue();
			return -1;
		}
		else{
			movieIndex = GetMovieIndex(movies, size, movie);
			if (movieIndex == -1){
				cout << "Movie Not found" << endl;
				movie = "";
				//PressKeyToContinue();
			}
			else
				return movieIndex;
		}
	}
}

int GetMovieIndex(Movie movies[], int size, string movie){
	for (int i = 0; i<size; i++){
		if (movies[i].title == movie)
			return i;
	}
	return -1;
}

void LoadMovies(Movie movies[]){

	int numMovies;

	ifstream infile;
	infile.open("movies.txt");
	infile >> numMovies;

	for (int i = 0; i<numMovies; i++){
		infile >> movies[i].title;
		infile >> movies[i].runTime;
		infile >> movies[i].expectedYield;
		Movie m = movies[i];
		m;
	}
	infile.close();
}

void LoadRooms(Movie movies[], int size){
	ifstream infile;
	infile.open("rooms.txt");

	for (int i = 0; i<size; i++){
		infile >> movies[i].roomID;
		infile >> movies[i].capacity;
		movies[i].available = movies[i].capacity;;   //initial availability is equal to capacity as no tickets are sold
	}
	infile.close();
}

void sortMovies(Movie*&movies, int numMovies)
{
	for (int i = 0; i < numMovies; i++){
		for (int j = i; j < numMovies; j++){
			if (movies[i].expectedYield < movies[j].expectedYield)
			{
				Movie m = movies[i];
				movies[i] = movies[j];
				movies[j] = m;
				m;
			}
		}
	}
}