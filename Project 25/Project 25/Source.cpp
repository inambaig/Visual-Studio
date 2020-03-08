#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include<fstream>
#include<math.h>

using namespace std;
int DocumentWidth = 0;
string ParagraphAlignment;
typedef  list< string> Words;

void AlignTextCenter(string s);
Words splitText(const  string &text);

void AlignTextLeft(string StringText)
{
	int Stringlength = StringText.length();
	int position = (int)((DocumentWidth - Stringlength));
	cout << "|";
	cout << StringText;
	for (int i = 0; i < position; i++)
		cout << " ";
	cout << "|\n";
}

void AlignParagraph(const  string &text)
{
	Words WordsInParagraph = splitText(text);

	string TextLine;
	for (Words::const_iterator it = WordsInParagraph.begin(); it != WordsInParagraph.end(); ++it) {
		if (TextLine.size() + it->size() + 1 > DocumentWidth) {
			if (ParagraphAlignment == "left"){
				AlignTextLeft(TextLine);
			}
			else if (ParagraphAlignment == "right")
			{
				cout.width(DocumentWidth);  cout << right << "|" + TextLine + "|" << '\n';
			}
			else if (ParagraphAlignment == "center")
			{
				AlignTextCenter(TextLine);
			}
			TextLine.clear();
			TextLine = *it;
		}
		else {
			if (!TextLine.empty()) {
				TextLine.append(" ");
			}
			TextLine.append(*it);
		}
	}
	if (ParagraphAlignment == "left"){
		AlignTextLeft(TextLine);
	}
	else if (ParagraphAlignment == "right")
	{
		cout.width(DocumentWidth);  cout << right << "|" + TextLine + "|" << '\n';
	}
	else if (ParagraphAlignment == "center")
	{
		AlignTextCenter(TextLine);
	}
}
void AlignTextCenter(string StringText)
{
	int Stringlength = StringText.length();
	int position = (int)((DocumentWidth - Stringlength) / 2);
	cout << "|";
	for (int i = 0; i<position; i++)
		cout << " ";

	cout << StringText;
	position = (int)ceil((DocumentWidth - Stringlength) / 2);
	for (int i = 0; i<position; i++)
		cout << " ";
	cout << "|\n";
}
string ReadTextFromFile()
{
	string ParagraphText, Line;
	ifstream InputFile;
	InputFile.open("InputParagraph.txt");
	while (!InputFile.eof())
	{
		getline(InputFile, Line);
		ParagraphText += Line;
	}
	InputFile.close();
	return ParagraphText;
}
Words splitText(const  string &text)
{
	Words WordsInParagraph;
	istringstream InputStream(text);
	string Temp;
	while (InputStream) {
		InputStream >> Temp;
		WordsInParagraph.push_back(Temp);
	}
	return WordsInParagraph;
}
int main()
{
	string UserInputs;
	int SplitPosition = 0;
	do{
		cout << "Enter left|Right|Center and paragraph width:  ";
		getline(cin, UserInputs);
		SplitPosition = UserInputs.find(" ");
		ParagraphAlignment = UserInputs.substr(0, SplitPosition);
		DocumentWidth = atoi((UserInputs.substr(SplitPosition, UserInputs.length())).c_str());
		if (DocumentWidth == 0)
			break;
		else if (!(ParagraphAlignment == "center" || ParagraphAlignment == "right" || ParagraphAlignment == "left"))
		{
			cout << "Invalid Justification command" << "\n";
		}
		else
		{
			AlignParagraph(ReadTextFromFile());
		}
	} while (DocumentWidth != 0);
	system("Pause");
	return 0;
}