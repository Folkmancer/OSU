#include <iostream>
#include "Temp_matrix.h"
using namespace std;

int main()
{
	setlocale(0, "");
	int colA, rowA, colB, rowB;
	float **matrixA(NULL), **matrixB(NULL), **matrixX(NULL),  **matrixY(NULL), **matrixZ(NULL), summ(0);
	cout << "Введите кол-во столбцов матрицы А: ";
	cin >> colA;
	cout << "Введите кол-во строк матрицы А: ";
	cin >> rowA;
	cout << "Введите кол-во столбцов матрицы B: ";
	cin >> colB;
	cout << "Введите кол-во строк матрицы B: ";
	cin >> rowB;
	
	alloc_matrix(colA, rowA, matrixA);
	cout << endl << "Матрица A";
	for (int row = 0; row < rowA; row++)
	{
		cout << endl;
		for (int col = 0; col < colA; col++)
		{
			matrixA[row][col] = 1 + rand() % 10;
			cout << matrixA[row][col] << " ";
		}
	}

	cout << endl << "\nМатрица B";
	alloc_matrix(colB, rowB, matrixB);
	for (int row = 0; row < rowB; row++)
	{
		cout << endl;
		for (int col = 0; col < colB; col++)
		{
			matrixB[row][col] = 1 + rand() % 10;
			cout << matrixB[row][col] << " ";
		}
	}

	cout << endl <<"\nСложение матриц A и B";
	matrixX = matrix_summ(colA, rowA, colB, rowB, matrixA, matrixB);
	if (matrixX == NULL) cout << "\nНе удовлетворяет правилу сложения матриц"; 
	else
	{
		for (int row = 0; row < rowB; row++)
		{
			cout << endl;
			for (int col = 0; col < colB; col++)
			{
				cout << matrixX[row][col] << " ";
			}
		}
		delete_matrix(rowA, matrixX);
	}

	cout << endl << "\nПроизведение матриц A и B";
	matrixY = multi_matrix(colA, rowA, colB, rowB, matrixA, matrixB);
	if (matrixY == NULL) 
	{ 
		cout << "\nНе удовлетворяет правилу произведения матриц"; 
	}
	else
	{
		for (int row = 0; row < rowA; row++)
		{
			cout << endl;
			for (int col = 0; col < colB; col++)
			{
				cout << matrixY[row][col] << " ";
			}
		}
		delete_matrix(rowA, matrixY);
	}

	cout << endl << "\nТранспонирование матрицы B";
	alloc_matrix(rowB, colB, matrixZ);
	matrixZ = transposition(colB, rowB, matrixB);
	
	for (int row = 0; row < colB; row++)
	{
		cout << endl;
		for (int col = 0; col < rowB; col++)
		{
			cout << matrixZ[row][col] << " ";
		}
	}

	cout << endl << "\nСумма главной диагонали матрицы A";
	summ = main_diag(colA, rowA, matrixA);
	cout << endl << summ << endl;
	cout << endl;

	delete_matrix(colB, matrixZ);
	delete_matrix(rowA, matrixA);
	delete_matrix(rowB, matrixB);
	
	system("pause");
	return 0;
}
