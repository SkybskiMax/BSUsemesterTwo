// MatrixExtension.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MatrixExtension.h"
#include <stdexcept>
#include <iostream>

using namespace std;

#pragma region MatrixFunc
MATRIXEXTENSION_API double** MatrixExt::GenerateRandomMatrix(int rows, int cols)
{
	double** matrix = AllocateMemory(rows, cols);
	FillRandomMatrix(matrix, rows, cols);
	return matrix;
}

MATRIXEXTENSION_API int** MatrixExt::GenerateRandomMatrixInt(int rows, int cols)
{
	int** matrix = AllocateMemoryInt(rows, cols);
	FillRandomMatrix(matrix, rows, cols);
	return matrix;
}

MATRIXEXTENSION_API double** MatrixExt::GenerateRandomSymmMatrix(int rows, int cols)
{
	double** matrix = AllocateMemory(rows, cols);
	FillRandomSymmMatrix(matrix, rows, cols);
	return matrix;
}

MATRIXEXTENSION_API double** MatrixExt::GenerateTaylorMatrix(int rows, int cols)
{
	double** matrix = AllocateMemory(rows, cols);
	FillTaylorMatrix(matrix, rows, cols);
	return matrix;
}

MATRIXEXTENSION_API double** MatrixExt::GenerateMatrix(int rows, int cols)
{
	double** matrix = AllocateMemory(rows, cols);
	FillMatrix(matrix, rows, cols);
	return matrix;
}

MATRIXEXTENSION_API	int ** MatrixExt::GenerateJaggedMatrix(int n, int* sizes)
{
	int** matrixA = new int*[n];
	for (int i = n, k = 0; i > 0; i--, k++)
	{
		matrixA[k] = new int[sizes[k]];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			matrixA[i][j] = rand() % 200;
		}
	}
	return matrixA;
}

MATRIXEXTENSION_API int * MatrixExt::GenerateSizesMatrix(int n)
{
	int* sizes = new int[n];
	for (int i = n - 1, k = 0; i >= 0; i--, k++)
	{
		sizes[k] = i + 1;
	}
	return sizes;
}

MATRIXEXTENSION_API void MatrixExt::FillRandomMatrix(double** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = -100 + rand() % 200;
		}
	}
}

MATRIXEXTENSION_API void MatrixExt::FillRandomMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = -100 + rand() % 200;
		}
	}
}

MATRIXEXTENSION_API void MatrixExt::FillRandomSymmMatrix(double** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = -100 + rand() % 200;
		}
	}
}

MATRIXEXTENSION_API void MatrixExt::FillTaylorMatrix(double** matrix, int rows, int cols)
{
	double eps = 0.00001;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (i == j)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = (CosTaylor(i + j, eps) - CosTaylor(i - j, eps)) / (i + j + 1) / (i + j + 1);
			}
		}
	}
}

MATRIXEXTENSION_API void MatrixExt::FillMatrix(double** matrix, int rows, int cols)
{
	double eps = 0.00001;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (i == j)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = (cos(i + j) - cos(i - j)) / (i + j + 1) / (i + j + 1);
			}
		}
	}
}

MATRIXEXTENSION_API void MatrixExt::DisplayMatrix(double** matrix, int rows, int cols)
{

	for (int i = 0; i < rows; ++i)
	{

		for (int j = 0; j < cols; ++j)
		{
			cout.width(6);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

MATRIXEXTENSION_API void MatrixExt::DisplayMatrix(bool** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout.width(6);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

MATRIXEXTENSION_API void MatrixExt::DisplayMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{

		for (int j = 0; j < cols; ++j)
		{
			cout.width(6);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

MATRIXEXTENSION_API void MatrixExt::DisplayDifferenceMatrix(int **matrixA, int **matrixB, int*sizes, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < sizes[i]; j++)
		{
			cout.width(5);
			cout << matrixA[i][j]-matrixB[i][j];;
			if ((i == n - j - 1) && j != n - 1)
			{
				for (size_t k = j + 1, p = j; k < n; k++)
				{
					cout.width(5);
					cout << matrixA[n - k - 1][n - i - 1]- matrixB[n - k - 1][n - i - 1];
				}
			}
		}
		cout << endl;
	}
	return;
}

MATRIXEXTENSION_API void MatrixExt::DisplayJaggedMatrix(int** matrixA, int*sizes, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < sizes[i]; j++)
		{
			cout.width(5);
			cout << matrixA[i][j];
			if ((i == n - j - 1) && j!=n-1)
			{
				for (size_t k = j+1, p=j; k < n; k++)
				{
					cout.width(5);
					cout << matrixA[n-k-1][n-i-1];
				}
			}
		}
		cout << endl;
	}
	return;
}

MATRIXEXTENSION_API double MatrixExt::CompareMatrix(double** matrixA, double** matrixB, int rows, int cols)
{
	double maxDiff = matrixA[0][0] - matrixB[0][0];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (fabs(matrixA[i][j] - matrixB[i][j]) > maxDiff);
			{
				maxDiff = fabs(matrixA[i][j] - matrixB[i][j]);
			}
		}
	}
	return maxDiff;
}

void cross(bool **a, int n, int m, int size)
{
	a[n][m] = 1;
	int n1 = n, m1 = m;
	while (n1 >= 0 && m1 >= 0)
	{
		a[n1--][m1--] = 1;
	}
	n1 = n;
	m1 = m;
	while (n1 >= 0 && m1 < size)
	{
		a[n1--][m1++] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		m1 = m;
		while (a[i][m1] == 0 && a[i][m1] >= 0)
		{
			a[i][m1--] = 1;
		}
		m1 = m + 1;
		while (a[i][m1] == 0 && a[i][m1] < size)
		{
			a[i][m1++] = 1;
		}
	}
	/*MatrixExt::DisplayMatrix(a,size,size);
	cout << endl;*/
}

MATRIXEXTENSION_API double MatrixExt::FindMaxElementInScope(double** matrix, int i, int j, int n)
{
	double max = matrix[i][j];
	bool **matb = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		matb[i] = new bool[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matb[i][j] = 0;
		}
	}
	cross(matb, i, j, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matb[i][j] && max < matrix[i][j])
			{
				max = matrix[i][j];
			}
		}
	}
	FreeMemory(matb, n);
	return max;
}

MATRIXEXTENSION_API double** MatrixExt::GenerateMatrixTask11(double** exMatrix, int rows, int cols)
{
	double** matrix = AllocateMemory(rows, cols);
	for (int j = 0, i = 0; j < cols; ++j)
	{
		matrix[i][j] = exMatrix[i][j];
	}
	for (int i = 1; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = FindMaxElementInScope(exMatrix, i, j, rows);
		}
	}
	return matrix;
}

#pragma endregion

#pragma region Memory
MATRIXEXTENSION_API void MatrixExt::FreeMemory(int** matrix, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

MATRIXEXTENSION_API void MatrixExt::FreeMemory(bool** matrix, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

MATRIXEXTENSION_API double** MatrixExt::AllocateMemory(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	double** a = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new double[cols];
	}

	return a;
}

MATRIXEXTENSION_API int** MatrixExt::AllocateMemoryInt(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** a = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[cols];
	}

	return a;
}
#pragma endregion

#pragma region TaylorFunctions
MATRIXEXTENSION_API double MatrixExt::SinTaylor(double x, double eps)
{
	double term = x, sum = 0;
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i) / (2 * i + 1);
	}
	return sum;
}

MATRIXEXTENSION_API double MatrixExt::CosTaylor(double x, double eps)
{
	double term = 1.0, sum = 0;

	int k = 0;

	double a = double(x) - 2 * 3.14159265359*k;

	while (a > 0)
	{
		k++;
		a = double(x) - 2 * 3.14159265359*k;
	}

	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * a * a / (2 * i - 1) / (2 * i);
	}
	return sum;
}
#pragma endregion

