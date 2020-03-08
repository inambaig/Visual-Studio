#include <iostream>

using namespace std;

#include <stdlib.h>

// implement the functions : add, sub, mult, transpose

class Matrix {

public:

	Matrix(int row, int col);

	int GetData();

	Matrix Transpose();

	int Display();

	Matrix Add(Matrix b);

	Matrix Multiply(Matrix b);
	Matrix Multiply2(Matrix b);

	int CompareRowCol(Matrix b);

private:

	int rows, cols;

	//int Term[rows][cols];

	int *Term;

};



Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
	Term = new int[rows * cols];
}



int Matrix::GetData() {

	int input_value;

	cout << "rows = " << rows << "  cols = " << cols << endl;

	for (int j = 0; j < rows * cols; j++)

	{

		cout << "term value = ";

		cin >> input_value;

		cout << " " << endl;

		Term[j] = input_value;

	}

	return 0;

}

Matrix Matrix::Add(Matrix b)
{

	int n;
	Matrix d(rows, b.cols);
	n = rows * cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			d.Term[i*cols + j] = Term[i*cols + j] + b.Term[i*cols + j];
	}

	cout << endl;

	return d;
}

Matrix Matrix::Transpose() {

	Matrix b(cols, rows);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int from = i*cols + j;
			int to = j*rows + i;
			b.Term[to] = Term[from];
		}
	}
	return b;

}



Matrix Matrix::Multiply(Matrix b) {

	if (cols != b.rows) cout << "Incompatible matrices" << endl;

	Matrix d(rows, b.cols);

	for (int i = 0; i < rows; i++)
	{
		cout << endl;
		for (int j = 0; j < b.cols; j++)
		{
			int sum = 0;
			for (int k = 0; k < cols; k++)
				sum += Term[i*cols + k] * b.Term[k*b.cols + j];
			d.Term[i*b.cols + j] = sum;
		}
	}
	return d;

}
Matrix Matrix::Multiply2(Matrix b) {

	if (cols != b.rows) cout << "Incompatible matrices" << endl;
	
	Matrix d(rows, b.cols);

	Matrix c = b.Transpose();
	d = Multiply(c);

	return d;

}


int Matrix::CompareRowCol(Matrix b) {

	if (cols != b.rows) return 1;

	else return 0;

}

int Matrix::Display() {

	int n;

	n = rows * cols;

	for (int i = 0; i < rows; i++)

	{

		cout << endl;

		for (int j = 0; j < cols; j++)

			cout << Term[i*cols + j] << " ";

	}

	cout << endl;

	return 0;

}



int main()

{

	Matrix a(2, 3);

	Matrix b(3, 4);

	Matrix c(2, 4);



	cout << "Enter first matrix: " << endl;

	a.GetData();

	cout << "Enter second matrix: " << endl;

	b.GetData();



	cout << "Display first matrix: " << endl;

	a.Display();

	cout << "Display second matrix: " << endl;

	b.Display();



	Matrix d(4, 3);

	d = b.Transpose();

	cout << "Transpose() of Matrix b" << endl;

	d.Display();



	/* If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again. */

	if (a.CompareRowCol(b))

	{

		cout << "Error! column of first matrix not equal to row of second.";

		cout << "Enter rows and columns for first matrix: ";

	}





	c = a.Multiply(b);//not using transpose()

	c.Display();

	c = a.Add(b);

	cout << "Multiply of Matrix a,b" << endl;

	c.Display();

	cout << "using transpose()"<<endl;

		c = a.Multiply2(b);//using transpose()

	c.Display();

	system("pause");

	return 0;

}