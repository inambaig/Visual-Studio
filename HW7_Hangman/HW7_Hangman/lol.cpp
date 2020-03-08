//#include <iostream>
//#include<sstream>
//using namespace std;
//
//string LolSpeak(string sentence)
//{
//	string short_[10] = { " ily ", " lol ", " yolo ", " u ", " brb ", " gtg ", " rofl ", " smh ", " r ", " btw " };
//	string short_ans[10] = { " i love you ", " laughing out loud ", " You only live once. ", " you ", " be right back ", " gotta go ", " Rolling on floor laughing ", " shaking my head ", " are ", " between " };
//
//	string corrected = "";
//	stringstream iss(sentence);
//	do
//	{
//		string subs;
//		iss >> subs;
//		subs = " " + subs + " ";
//		int v = 0;
//		for (int j = 0; j<10; j++)
//		{
//			if (subs == short_[j])
//			{
//				corrected += short_ans[j];
//				v = 1;
//				break;
//			}
//
//
//		}
//		if (v == 0)
//		{
//			corrected += subs;
//			v = 0;
//		}
//
//
//	} while (iss);
//
//	return corrected;
//}
//int main()
//{
//
//	char Input[80];
//	cout << "This program will correct ur lolspeak abrreviations" << endl;
//	cout << "Enter a sentence: ";
//	cin.getline(Input, 80, '\n');
//	string Sentence = Input;
//	cout << "The corrected sentence : ";
//	string corrected = LolSpeak(Sentence);
//	cout << endl << corrected << endl;
//	system("pause");
//	return 0;
//}
//
