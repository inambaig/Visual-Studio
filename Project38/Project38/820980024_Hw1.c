
float  computeArea(int *v1, int *v2, int shape)
{
	float areaComputed = 0.0;
	// this if will execute if shape = 1
	if (shape == 1)
	{
		// 1 triangle
		// calculating area of triangle
		areaComputed = (double)((*v1)*(*v2)) / (double)2;
	}
	// this if will execute if shape = 2
	else if (shape == 2)
	{
		// 2 square
		// calculating area of square
		areaComputed = ((*v1)*(*v2));
	}
	// this if will execute if shape = 3
	else if (shape == 3)
	{
		// 3 circle
		// calculating radius
		float radius = (float)(((double)*v1) / (double)2);
		// calculating area of circle
		areaComputed = ((double)22 / 7) * (radius*radius);
	}
	return(areaComputed);

}
int numTimesAppears(char  *mystring, char ch)
{
	int i;
	int count = 0;
	// stores the length of string passed as parameter
	int length = strlen(mystring);

	// traverse till end of string
	for (i = 0; i<length; i++)
	{
		// it will execute if the character at current index matches the passed parameter

		if (mystring[i] == ch)
			// incerements the count
			count++;
	}
	// returns the count
	return(count);
}

