#pragma once

void DisplayMatrix(int**, int);
int** GenerateMatrixTask3(int**, int);
int** AllocateMemory(int);
int FindMaxElementInScope(int**, int, int, int);

using namespace std;

void DisplayMatrix(int** matrix, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int** GenerateMatrixTask3(int** exMatrix, int size)
{
	int** matrix = AllocateMemory(size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = FindMaxElementInScope(exMatrix, i, j, size);
		}
	}
	return matrix;
}

//int FindMaxElementInScope(int** matrix, int i, int j, int size)
//{
//	int max = matrix[i][j];
//	int leftI = i, leftJ = j;
//	int rightI = i, rightJ = j;
//
//	for (; i >= 0; i--)
//	{
//		for (int j = 0; (leftJ > 0) && (rightJ < size); leftJ--,rightJ++)
//		{
//			for (int j = rightJ; leftI < rightI; i++)
//			{
//				if (max < matrix[i][j])
//				{
//					max = matrix[i][j];
//				}
//			}
//		}
//	}
//	return max;
//}

int FindMaxElementInScope(int** matrix, int i, int j, int size)
{
	int itemp = 0, jtemp = 0, max = 0;

	if (i + j < size - 1)
	{
		itemp = i;
		jtemp = j;
		max = matrix[itemp][jtemp];

		for (; itemp < size-1 ; itemp++)
		{
			for (; itemp+jtemp < size-1; jtemp++)
			{
				if (max < matrix[itemp][jtemp])
				{
					max = matrix[itemp][jtemp];
				}
			}
			jtemp = j;
		}
	}
	else if (i + j > size - 1)
	{
		itemp = i;
		jtemp = j;
		max = matrix[itemp][jtemp];

		for (; itemp+jtemp > size - 1; itemp--)
		{
			for (; itemp + jtemp > size - 1; jtemp--)
			{
				if (max < matrix[itemp][jtemp])
				{
					max = matrix[itemp][jtemp];
				}
			}
			jtemp = j;
		}
	}
	else if (j + i == size - 1)
		max = matrix[i][j];

	return max;
}


int** AllocateMemory(int size)
{
	if (size <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
	}

	return matrix;
}