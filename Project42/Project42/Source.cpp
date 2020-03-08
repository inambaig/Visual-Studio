//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//struct studentType
//{
//	string studentFName;
//	string studentLName;
//	int testScore;
//	char grade;
//};
//
//// a. A function to read the students’ data into the array.
//void readFile(studentType studArray[], ifstream&in)
//{
//	for (int i = 0; i < 20; i++)
//	{
//		in >> studArray[i].studentFName;
//		in >> studArray[i].studentLName;
//		in >> studArray[i].testScore;
//	}
//}
//
//// b. A function to assign the relevant grade to each student. 
//void AssignGrade(studentType studArray[])
//{
//	for (int i = 0; i < 20; i++)
//	{
//		if (studArray[i].testScore >= 90)
//		{
//			studArray[i].grade = 'A';
//		}
//		else if (studArray[i].testScore >= 80)
//		{
//			studArray[i].grade = 'B';
//		}
//		else if (studArray[i].testScore >= 70)
//		{
//			studArray[i].grade = 'C';
//		}
//		else if (studArray[i].testScore >= 60)
//		{
//			studArray[i].grade = 'D';
//		}
//		else
//		{
//			studArray[i].grade = 'F';
//		}
//	}
//}
//
//// c. A function to find the highest test score. 
//int highestScore(studentType studArray[])
//{
//	int highest = 0;
//	for (int i = 0; i < 20; i++)
//	{
//		if (studArray[i].testScore > highest)
//		{
//			highest = studArray[i].testScore;
//		}
//	}
//	return highest;
//}
//// d. A function to print the names of the students having the highest test score. 
//void dislayHighest(studentType studArray[], int highest, ofstream &out)
//{
//	cout << endl << "Students with highest scores" << endl;
//	out << endl << "Students with highest scores" << endl;
//	for (int i = 0; i < 20; i++)
//	{
//		if (studArray[i].testScore == highest)
//		{
//			cout << studArray[i].studentLName << ", " << studArray[i].studentFName << "\t" << studArray[i].testScore << "\t" << studArray[i].grade << endl;
//			out << studArray[i].studentLName << ", " << studArray[i].studentFName << "\t" << studArray[i].testScore << "\t" << studArray[i].grade << endl;
//		}
//	}
//}
//
//// Display all students
//void displayStudents(studentType studArray[], ofstream &out)
//{
//
//	for (int i = 0; i < 20; i++)
//	{
//			cout << studArray[i].studentLName << ", " << studArray[i].studentFName << "\t" << studArray[i].testScore << "\t" << studArray[i].grade << endl;
//			out << studArray[i].studentLName << ", " << studArray[i].studentFName << "\t" << studArray[i].testScore << "\t" << studArray[i].grade << endl;
//	}
//}
//
//
//void main()
//{
//	ifstream in("input.txt");
//	ofstream out("output.txt");
//
//	studentType studArray[20];
//
//	readFile(studArray, in);
//	AssignGrade(studArray);
//	displayStudents(studArray, out);
//	dislayHighest(studArray, highestScore(studArray), out);
//	system("pause");
//}