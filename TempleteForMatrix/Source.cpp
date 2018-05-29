#include <iostream>
#include "Temp_matrix.h"
using namespace std;

int main()
{
	setlocale(0, "");
	int colA, rowA, colB, rowB;
	float **matrixA(NULL), **matrixB(NULL), **matrixX(NULL),  **matrixY(NULL), **matrixZ(NULL), summ(0);
	cout << "������� ���-�� �������� ������� �: ";
	cin >> colA;
	cout << "������� ���-�� ����� ������� �: ";
	cin >> rowA;
	cout << "������� ���-�� �������� ������� B: ";
	cin >> colB;
	cout << "������� ���-�� ����� ������� B: ";
	cin >> rowB;
	
	alloc_matrix(colA, rowA, matrixA);
	cout << endl << "������� A";
	for (int row = 0; row < rowA; row++)
	{
		cout << endl;
		for (int col = 0; col < colA; col++)
		{
			matrixA[row][col] = 1 + rand() % 10;
			cout << matrixA[row][col] << " ";
		}
	}

	cout << endl << "\n������� B";
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

	cout << endl <<"\n�������� ������ A � B";
	matrixX = matrix_summ(colA, rowA, colB, rowB, matrixA, matrixB);
	if (matrixX == NULL) cout << "\n�� ������������� ������� �������� ������"; 
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

	cout << endl << "\n������������ ������ A � B";
	matrixY = multi_matrix(colA, rowA, colB, rowB, matrixA, matrixB);
	if (matrixY == NULL) 
	{ 
		cout << "\n�� ������������� ������� ������������ ������"; 
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

	cout << endl << "\n���������������� ������� B";
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

	cout << endl << "\n����� ������� ��������� ������� A";
	summ = main_diag(colA, rowA, matrixA);
	cout << endl << summ << endl;
	cout << endl;

	delete_matrix(colB, matrixZ);
	delete_matrix(rowA, matrixA);
	delete_matrix(rowB, matrixB);
	
	system("pause");
	return 0;
}
