////Header file section
//#include<string.h>
//#include<string>
//#include<cstring>
//#include<iostream>
//#include <sstream>
//#include<cstdlib>
////namespace to avoid naming conventions
//using namespace std;
////Program execution
//int main()
//{
//	//Declare the variables
//	char ch = 'y';
//	char time_str[100];
//	char del[] = ":";
//	char *delim = NULL, d = ':';
//
//	string hr, min;
//	string time;
//	int i, len, flag = 1;
//	// Prompt the user to enter the time through the
//	// keyboard
//
//	// Run a loop that asks the user to enter the strings until
//	// the user wins a lottery
//	do {
//		cout << "Enter a time (HH:MM):";
//		cin >> time;
//		if (ch == 'y') {
//			strcpy_s(time_str, time.c_str());
//			len = strlen(time_str);
//			// Check whether the time contains the colon between
//			// the hours and minutes
//			for (i = 0; i < len; i++)
//			{
//				if (time_str[i] == ':')
//				{
//					flag = 2;
//					//break;
//				}
//			}
//
//			//If the time contains colon, then control comes
//			//to this if condition
//			if (flag == 2)
//			{
//				//Store the time before colon as hr
//				hr = strtok_s(time_str, del, &delim);
//				//Store the time after comma as min
//				min = strtok_s(NULL, del, &delim);
//				int hr1 = stoi(hr);
//				int h1 = hr1 / 10;
//				int h2 = stoi(hr);
//				h2 = h2 % 10;
//				int min1 = stoi(min);
//				min1 = min1 / 10;
//				int min2 = stoi(min);
//				min2 = min2 % 10;
//
//				if (hr1 < 10)
//				{
//					if (h2 == min1 && h2 == min2)
//					{
//						cout << h2 << ":" << min1 << min2;
//						cout << "is a normal time. " << "->";
//						cout << "BINGO! Go to buy a lottery";
//						cout << "ticket." << endl;
//					}
//					if (h2 == (min1 - 1) && h2 == (min2 - 2))
//					{
//						cout << h2 << ":" << min1 << min2;
//						cout << "is a normal time. " << "->";
//						cout << "UP! All dreams will come";
//						cout << "true."
//							<< endl;
//					}
//					if (h2 == (min1 + 1) && h2 == (min2 + 2))
//					{
//						cout << h2 << ":" << min1 << min2;
//						cout << "is a lucky time. " << "->";
//						cout << "Down! Challenging road is ";
//						cout << "ahead." << endl;
//					}
//
//
//					else
//						cout << h2 << ":" << min1 << min2;
//					cout << " is a normal time. " << endl;
//				}
//				if ((h1 + h2) == (min1 + min2))
//					cout << "Lucky time" << endl;
//
//
//			}
//			else
//			{
//				flag = 0;
//
//				cout << "Error: No colon in the time";
//				cout << endl;
//				cout << "Wrong format" << endl;
//			}
//
//			//Re-enter the time
//
//
//			cout << "Run again(y/n)?" << endl;
//			cin >> ch;
//			flag = 1;
//		}
//		if (ch == 'n')
//		{
//			cout << "James Leo Good Bye!";
//			//system("pause");
//			exit(0);
//
//		}
//
//	} while (ch != 'n' || ch != 'N');
//}