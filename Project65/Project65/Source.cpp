#include <iostream>
using namespace std;

void readInput(float *english, float *history, float *Cpp, float *Math)
{
	cout << "Enter grades of the class for the following courses." << endl;
	cout << "English ";
	for (int i = 0; i < 10; i++)
	{
		cin >> english[i];
	}
	cout << "History ";
	for (int i = 0; i < 10; i++)
	{
		cin >> history[i];
	}
	cout << "CPP ";
	for (int i = 0; i < 10; i++)
	{
		cin >> Cpp[i];
	}
	cout << "Math ";
	for (int i = 0; i < 10; i++)
	{
		cin >> Math[i];
	}
}

float calculateAverage(float *course)
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += course[i];
	}
	return sum / 10;
}
int main()
{
	float english[10], history[10], Cpp[10], Math[10];
	readInput(english, history, Cpp, Math);
	float englishAverage = calculateAverage(english);
	float historyAVerage = calculateAverage(history);
	float cppAverage = calculateAverage(Cpp);
	float mathAverage = calculateAverage(Math);

	float BeverlyEnglishScores = 0;
	float BeverlyHistoryScores = 0;
	float BeverlyCPPScores = 0;
	float BeverlyMathScores = 0;
	cout << "Beverly’s Grades" << endl;
	cout << "English ";
	cin >> BeverlyEnglishScores;
	cout << "History ";
	cin >> BeverlyHistoryScores;
	cout << "CPP ";
	cin >> BeverlyCPPScores;
	cout << "Math ";
	cin >> BeverlyMathScores;

	cout << "Difference of Beverly with class average " << endl;
	cout << "English " << BeverlyEnglishScores - englishAverage << endl;
	cout << "History " << BeverlyHistoryScores - historyAVerage << endl;
	cout << "CPP " << BeverlyCPPScores - cppAverage << endl;
	cout << "Math " << BeverlyMathScores - mathAverage << endl;

	system("pause");
	return 0;
}