#include <iomanip>
#include <iostream>

using namespace std;

void input(float** a,int j,int i,const int row,const int col)
{
	cout << "a[" << i << "][" << j << "]=";
	cin >> a[i][j];
	if (j < col-1 )
		input(a, j + 1, i, row, col);
	else
		if (i < row - 1)
		{
			cout << endl;
			input(a, 0, i + 1, row, col);
		}
}

void Print(float** a, const int row, const int col,int i, int j)
{
	cout << setw(5) << a[i][j];
	if (j < col - 1)
		Print(a, row, col, i, j + 1);
	else if (i<row-1)
    {
        cout << endl;
		Print(a, row, col, i + 1, 0);
    }
}

int find(float** a, const int row, const int inequality, int& quantity,int j,int i,float& avarage)
{
	if (j < row && i<row)
	{
		avarage += a[i][j] / row;
		find(a, row, inequality, quantity, j+1, i, avarage);
	}

	else if (i < row)
	{

		if (avarage < inequality)
			quantity += 1;
		avarage = 0;
		find(a, row, inequality, quantity, 0, i + 1, avarage);
	}
	return quantity;
}

int main()
{
	int row, col, inequality, i = 0, j = 0, quantity = 0;
	float avarage = 0.0;

	cout << "row="; cin >> row;
	cout << "col="; cin >> col;
	cout << "Enter the number "; cin >> inequality;

	float** a = new float* [row];
	for (int i = 0; i < row; i++)
		a[i] = new float[col];

	cout << endl;
	input(a, j, i, row, col);
	
	cout <<setw(5)<<find(a,row,inequality,quantity,j,i,avarage)<< endl;
	
	Print(a, row, col, i, 0);
	
	return 0;
}