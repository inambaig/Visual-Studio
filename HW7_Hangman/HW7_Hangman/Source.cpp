//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//
//VOID WINAPI SetConsoleColors(WORD attribs) {
//	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	CONSOLE_SCREEN_BUFFER_INFOEX cbi;
//	cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
//	GetConsoleScreenBufferInfoEx(hOutput, &cbi);
//	cbi.wAttributes = attribs;
//	SetConsoleScreenBufferInfoEx(hOutput, &cbi);
//}
//void main()
//{
//	srand(time(NULL));
//	//Please demo to the instructor or upload .cpp to Ecampus    Hangman Pseudo Code
//	//	1. Do a nice introduction screen for your hangman program (do this step last).
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
//		//cin >> Letter;
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
//
//	_getch();
//
//	//	2. Select a random word and store it in a string variable name SecretWord.
//	//	3. Create GuessWord which will be the same size as SecretWord, but all periods (e.g. ". . . . . . . .") string GuessWord  = SecretWord;  for (int x  = 0; x < SecretWord.size(); x++)  { if (SecretWord[x] == ' ')        GuessWord[x] = ' ';      else        GuessWord[x] = '.';  }
//	//4. Declare an integer named BadGuesses  = 0      Declare a string named Letter       Declare an integer named Location
//	//	5. Set up a while loop for steps 6 ­ 10.It should loop as long as BadGuesses < 6 and GuessWord  != SecretWord.This is the main loop of the program.The game keeps playing as long as you haven't lost (when BadGuesses = 6) and you haven't won (when GuessWord  = SecretWord).
//	//{      // This is the opening brace for the main while loop in the program
//	//	6. Display Graphics (do this step last)
//	//		7. Display Letters Already Guessed (do this step last)
//	//		8. Cout the GuessWord variable (the placeholder will all periods)
//	//		9. Prompt player to enter a letter (their guess) and store it in the variable Letter.Add this letter to LettersGuessed.
//	//		10. If Letter is not located in SecretWord (note: use Letter.find(), increment BadGuesses
//	//		Else continue looping and find all occurences of Letter in GuessWord and replace the periods.    // Step 10    Location = SecretWord.find(Letter,0);      if (Location > SecretWord.size())        BadGuesses++;      else        while (Location < SecretWord.size())      {        GuessWord.replace(Location,1,Letter);        Location = SecretWord.find(Letter, Location + 1);       }
//	//}
//}