//#include <iostream>
//#include <string>
//#include <sstream>
//#include <algorithm>
//#include <iterator>
//using namespace std;
//
//int countCharacter(string x, char y)
//{
//	int count = 0;
//	for (int i = 0; i < x.length(); i++)
//	{
//		if (x[i] == y)
//			count++;
//	}
//	return count;
//}
//
//void split2(const std::string& str, string*& cont, char delim = ' ')
//{
//	int counter = 0;
//	std::stringstream ss(str);
//	std::string token;
//	while (std::getline(ss, token, delim)) {
//		cont[counter++] = token;
//	}
//}
//string removeQuotes(string x)
//{
//	string newString = "";
//	for (int i = 0; i < x.length(); i++)
//	{
//		if (x[i] != '\"')
//			newString += x[i];
//	}
//	return newString;
//}
//
//int solution(string &S, string &T, string &U)
//{
//	S = removeQuotes(S);
//	U = removeQuotes(U);
//	T = removeQuotes(T);
//	int UCount = countCharacter(U, ',');
//	string*Uarray = new string[UCount+1];
//	split2(U, Uarray, ',');
//	for (int i = 0; i < UCount+1; i++)
//	{
//		string newString = "";
//		for (int j = 1; j < Uarray[i].length() - 1; j++)
//		{
//			newString += Uarray[i][j];
//		}
//		if (!(S.find(newString) != std::string::npos))
//		{
//			return -1;
//		}
//		else
//		{
//			int TCount = countCharacter(T, ',');
//			
//			string*Tarray1 = new string[TCount+1];
//			split2(U, Tarray1, ',');
//			TCount /= 2;
//			string**Tarray = new string*[TCount+1];
//			for (int i = 0; i < TCount; i++)
//				Tarray[i] = new string[2];
//			for (int i = 0; i < TCount*2; i++)
//			{
//				if (i % 2 == 0)
//				{
//					Tarray[i / 2][0] = Tarray1[i];
//				}
//				else
//				{
//					Tarray[i / 2][0] = Tarray1[i];
//				}
//			}
//
//			int SCount = countCharacter(T, '\\n');
//			SCount += 1;
//			string*Sarray1 = new string[SCount];
//			split2(S, Sarray1, '\\n');
//
//			string**Sarray = new string*[SCount];
//			for (int i = 0; i < SCount; i++)
//			{
//				Sarray[i] = new string[3];
//			}
//			for (int i = 0; i < SCount; i++)
//			{
//				split2(Sarray1[i], Sarray[i], ',');
//			}
//
//			int renmaining = 0;
//
//			for (int i = 0; i < SCount; i++)
//			{
//				bool found = false;
//				for (int j = 0; j < TCount; j++)
//				{
//					if (Sarray[i][1] == Tarray[j][1])
//						found = true;
//				}
//				if (!found)
//					renmaining += stoi(Sarray[i][2]);
//			}
//			return renmaining;
//		}
//	}
//	return 3;
//}
//void main()
//{
//	string S = "Netherlands,1,25000\\nNetherlands,2,3000\\nNetherlands,3,1000";
//	string T = "Netherlands,1";
//	string U = "Netherlands";
//	cout << solution(S,T , U);
//	system("pause");
//}