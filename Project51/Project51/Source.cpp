#include <stdio.h>
#include <string>

void printBoard(int** B, int size)
{
	printf("(");
	for (int i = 1; i < size; i++)
	{
		if (i != size - 1)
		{
			printf("%d, ", B[i][0]);
		}
		else
		{
			printf("%d)\n", B[i][0]);
		}
	}
}
void removeQueen(int** B, int size, int i, int j)
{
	B[i][0] = 0;
	B[i][j] = 0;
	for (int m = 1; m < size; m++)
	{
		if ((i + m) < size)
		{
			B[i + m][j] = B[i + m][j] + 1;
		}
	}
	for (int n = 1; n < size; n++)
	{
		if ((i + n) < size && (j + n) < size)
		{
			B[i + n][j + n] = B[i + n][j + n] + 1;
		}
	}
	for (int l = 1; l < size; l++)
	{
		if ((i + l) < size && (j - l) > 0)
		{
			B[i + l][j - l] = B[i + l][j - l] + 1;
		}
	}
}
	void placeQueen(int**B, int size, int i, int j)
	{
		if (i > (size - 1))
		{
			if (B[0][1] == 1)
			{
				printBoard(B, size);
			}

			B[0][0] = B[0][0] + 1;
		}
		else
		{
			for (int m = 1; m < size; m++)
			{
				if (B[i][m] == 0)
				{
					B[i][0] = m;
					B[i][m] = 1;
					for (int n = 1; n < size; n++)
					{
						if ((i + n) < size)
						{
							B[i + n][m] = B[i + n][m] - 1;
						}
					}
					for (int l = 1; l < size; l++)
					{
						if ((i + l) < size && (m + l) < size)
						{
							B[i + l][m + l] = B[i + l][m + l] - 1;
						}
					}
					for (int k = 1; k < size; k++)
					{
						if ((i + k) < size && (m - k) > 0)
						{
							B[i + k][m - k] = B[i + k][m - k] - 1;
						}
					}
					placeQueen(B, size, i + 1, 1);
					removeQueen(B, size, i, m);
				}
			}
		}
	}

	int findSolutions(int** B, int size, int i, char* mode)
	{
		if (mode[0] == '-' && mode[1] == 'v')
		{
			B[0][1] = 1;
		}
		placeQueen(B, size, i, 1);
		return B[0][0];
	}
	void main(int argc, char**argv)
	{
		int numsolutions = 0;
		int boardSize = 0;
		
			if (argc < 1)
			{
				printf("Usage: Queens [-v] number\n");
				printf("Option: -v verbose output, print all solutions\n");
				exit(1);
			}
			else if (argc == 2)
			{
				boardSize = atoi(argv[2]);
				int** B = new int*[boardSize + 1];
				for (int i = 0; i < boardSize + 1; i++)
				{
					B[i] = new int[boardSize + 1];
					for (int j = 0; j < boardSize; j++)
					{
						B[i][j] = 0;
					}
				}
				numsolutions = findSolutions(B, boardSize+1, 1, "");
			}
			else
			{
				if (argv[1] == argv[1])
				{
					boardSize = atoi(argv[2]);
					int** B = new int*[boardSize + 1];
					for (int i = 0; i < boardSize + 1; i++)
					{
						B[i] = new int[boardSize + 1];
						for (int j = 0; j < boardSize; j++)
						{
							if (j == 2)
								B[i][j] = 1;
							else
								B[i][j] = 0;
						}
						
					}
					B[2][2] = 1;
					numsolutions = findSolutions(B, boardSize + 1, 1, "-v");
				}
				else
				{
					printf("Incorrect parameters");
					exit(1);
				}
			}
			printf("%d -Queens has %d solutions\n", boardSize, numsolutions);
			system("pause");
}
