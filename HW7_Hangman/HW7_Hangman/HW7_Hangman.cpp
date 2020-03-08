//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//
//void main()
//{
//	srand(time(NULL));
//	
//	//declaration
//	string dictionary[10] = { "should", "where", "when", "circumstances", "graphics", "entry", "enter", "how", "what", "do" };
//	//Step1
//	cout << "\t\t\t\t";
//	Sleep(500);
//	cout << "W";
//	Sleep(100);
//	cout << "E";
//	Sleep(100);
//	cout << "L";
//	Sleep(100);
//	cout << "C";
//	Sleep(100);
//	cout << "O";
//	Sleep(100);
//	cout << "M";
//	Sleep(100);
//	cout << "E";
//	Sleep(100);
//	cout << " ";
//	cout << "T";
//	Sleep(100);
//	cout << "O";
//	Sleep(100);
//	cout << " ";
//	cout << "H";
//	Sleep(100);
//	cout << "A";
//	Sleep(100);
//	cout << "N";
//	Sleep(100);
//	cout << "G";
//	Sleep(100);
//	cout << "M";
//	Sleep(100);
//	cout << "A";
//	Sleep(100);
//	cout << "N";
//	Sleep(100);
//	cout << endl << endl;
//	cout << "The game HANGMAN is about gessing a secret word. The number of letters in the secret word is shown using the '.' symbol in the guess word.";
//	cout << "So the game is about entering different characters to form the secret word. There are total 6 bad guesses available. So you need to guess";
//	cout << "the word before 6 bad guesses to get the winning card. Good Luck.";
//	cout << endl << endl;
//	//Step 2
//	string SecretWord = dictionary[rand()%10];
//	// Step 3
//	string GuessWord = SecretWord;
//	for (int x = 0; x < SecretWord.size(); x++)
//	{
//		if (SecretWord[x] == ' ')
//			GuessWord[x] = ' ';
//		else
//			GuessWord[x] = '.';
//	}
//
//	//Step 4
//	int BadGuesses = 0;
//	string Letter;
//	int Location;
//	string LettersGuessed = "";
//	//Step5
//	while (BadGuesses < 6 && GuessWord != SecretWord)
//	{
//		cout << endl;
//		//Step 6 display Graphics
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand()%15 + 1);
//		//Step 7
//		cout << "Letters already guessed : " << LettersGuessed << endl;
//
//		// Step 8
//		cout << "The guess word is : "<<GuessWord<<endl;
//		// Step 9
//		cout << "Enter a letter : ";
//		getline(cin, Letter);
//		LettersGuessed += Letter;
//		// Step 10
//		Location = SecretWord.find(Letter, 0);
//		if (Location > SecretWord.size())
//			BadGuesses++;
//		else
//		{
//			while (Location < SecretWord.size())
//			{
//				GuessWord.replace(Location, 1, Letter);
//				Location = SecretWord.find(Letter, Location + 1);
//			}
//		}
//	}
//
//	if (BadGuesses >= 6)
//	{
//		cout << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 15 + 1);
//		cout << "Unfortunately you lost it! \n";
//	}
//	else
//	{
//		cout << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 15 + 1);
//		cout << "The word is : " << SecretWord << endl << endl;
//		cout << "Congratulations. You won";
//	}
//	
//}