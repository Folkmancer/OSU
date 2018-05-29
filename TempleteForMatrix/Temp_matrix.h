#ifndef Temp_matrix
#define Temp_matrix

template<typename T> void alloc_matrix(int colA, int rowA, T ** &matrix)
{
	matrix = new T*[rowA];
	for (int row = 0; row < rowA; row++)
	{
		matrix[row] = new T[colA];
	}
}

template<typename T> void delete_matrix(int rowA, T ** &matrix)
{
	for (int row = 0; row < rowA; row++)
	{
		delete[]matrix[row];
	}
	delete[]matrix;
}

template<typename T> T ** matrix_summ(int colA, int rowA, int colB, int rowB, T ** matrixA, T ** matrixB)
{
	T ** matrixZ(NULL);
	if ((colA == colB) && (rowA == rowB))
	{
		alloc_matrix(colA, rowA, matrixZ);
		for (int row = 0; row < rowA; row++)
			for (int col = 0; col < colA; col++)
			{
				matrixZ[row][col] = matrixA[row][col] + matrixB[row][col];
			}
	}
	return matrixZ;
}

template<typename T> T ** multi_matrix(int colA, int rowA, int colB, int rowB, T ** matrixA, T ** matrixB)
{
	T ** matrixZ(NULL);
	if (colB == rowA)
	{
		alloc_matrix(colB, rowA, matrixZ);
		for (int row = 0; row < rowA; row++)
		{
			for (int col = 0; col < colB; col++)
			{
				matrixZ[row][col] = 0;
				for (int inner = 0; inner < colA; inner++)
				{
					matrixZ[row][col] += (matrixA[row][inner] * matrixB[inner][col]);
				}
			}
		}
	}
	return matrixZ;
}

template<typename T> T main_diag(int colA, int rowA, T ** matrix)
{
	T summ(0);
	for (int row = 0; row < rowA; row++)
	{
		for (int col = 0; col < colA; col++)
		{
			if (row == col) summ += matrix[row][col];
		}
	}
	return summ;
}

template<typename T> T ** transposition(int colA, int rowA, T ** matrix)
{
	T ** matrixZ(NULL);
	alloc_matrix(rowA, colA, matrixZ);
	for (int row = 0; row < rowA; row++)
	{
		for (int col = 0; col < colA; col++)
		{
			 matrixZ[col][row] = matrix[row][col];
		}
	}
	return matrixZ;
}

#endif
