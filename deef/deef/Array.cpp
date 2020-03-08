#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

// 7. Write a function that takes an object of class Array<string> and displays all the elements in the array, in order

void display(Array<string> obj)
{
	for (int i = 0; i < obj.length(); i++)
	{
		cout << obj[i] << "\n";
	}
}

int main()
{
	// 1. Declare a dynamic array of strings (using Array class) called strArray with an initial size of 2
	Array<string> strArray(2);

	// 2. Initialize the first 2 elements of the array to be the first 2 lines of a nursery rhyme -- yes, I wish my kids were younger :)

	// 2.1 the first element is "Twinkle, Twinkle, little star"
	// 2.2 the second element is "How I wonder what you are"
	strArray[0] = "Twinkle, Twinkle, little star";
	strArray[1] = "How I wonder what you are";

	// 3. expand the array to have a size of 4, so that we can add 2 more elements to the array
	strArray.changeSize(4);

	// 4. Set the third and the fourth elements to be "Up above the world so high", and "Like a diamond in the sky"

	strArray[2] = "Up above the world so high";
	strArray[3] = "Like a diamond in the sky";
	// 5. expand the array to have a size of 6, so that we can add 2 more elements to the array
	strArray.changeSize(6);
	// 6. Set the fifth and the sixth elements to be "Twinkle, Twinkle, little star", and "How I wonder what you are"

	strArray[4] = "Twinkle, Twinkle, little star";
	strArray[5] = "How I wonder what you are";
	// 8. Call the function that you wrote in Step 7, and feel nostalgic about this rhyme..
	display(strArray);
	return 0;
}
