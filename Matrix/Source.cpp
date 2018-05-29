#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void tranMatrix(int m, int n, int** matrix2)
{
	int t;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			t = matrix2[row][col];
			matrix2[row][col] = matrix2[col][row];
			matrix2[col][row] = t;
		}
	}
}

int main() {
	setlocale(0, "");
	srand(time(0));
	int m = 3, n = 3;
	cout << "Введите количество строк матрицы A: ";
	cin >> m;
	cout << "Введите количество столбцов матрицы A: ";
	cin >> n;

	int **matrix1 = new int*[100], **matrix2 = new int*[100], **matrix3 = new int*[100], row, col, inner;
	for (int count = 0; count < 100; count++)
	{
		matrix1[count] = new int[100]; // col
	}
	for (int count = 0; count < 100; count++)
	{
		matrix2[count] = new int[100]; // col
	}
	for (int count = 0; count < 100; count++)
	{
		matrix3[count] = new int[100]; // col
	}
	if (m == n) cout << "Матрица A (mxm)" << endl;
	else cout << "Матрица A (mxn)" << endl;
	for (row = 0; row < m; row++) //Initialize the first array							
	{
		for (col = 0; col < n; col++)
		{
			matrix1[row][col] = -3 + rand() % 9;
			cout << setw(3) << matrix1[row][col];
		}
		cout << endl;
	}
	//Copy matrix A
	for (row = 0; row < m; row++) //Initialize the second array							
	{
		for (col = 0; col < n; col++)
		{
			matrix2[row][col] = matrix1[row][col];
		}
	}
	if (m != n)
	{
		cout << "Транспонированная матрицы A (nxm)" << endl;
		tranMatrix(m, n, matrix2);
		for (row = 0; row < n; row++)
		{
			for (col = 0; col < m; col++)
			{
				cout << setw(3) << matrix2[row][col];
			}
			cout << endl;
		}
	}
	for (row = 0; row < m; row++) // Reset the third array
	{
		for (col = 0; col < m; col++)
		{
			matrix3[row][col] = 0;
		}
	}
	cout << "Результат произведения матриц AA" << endl;
	for (row = 0; row < m; row++)
	{
		for (col = 0; col < m; col++)
		{
			for (inner = 0; inner < n; inner++)
			{
				matrix3[row][col] += matrix1[row][inner] * matrix2[inner][col];
			}
			cout << setw(3) << matrix3[row][col];
		}
		cout << endl;
	}
	for (int count = 0; count < 100; count++) delete[] matrix1[count];
	for (int count = 0; count < 100; count++) delete[] matrix2[count];
	for (int count = 0; count < 100; count++) delete[] matrix3[count];
	system("pause");
	return 0;
}