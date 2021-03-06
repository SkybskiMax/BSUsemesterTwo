#include "stdafx.h"
#include "FileWork.h"
#include "MatrixFunctions.h"

using namespace std;


int main()
{
	const int N = 30;
	char fileName[N] = "matrix.txt";
	int n=6;
	system("cls");

	int** matrix = InitMatrix(fileName, n);
	DisplayMatrix(matrix, n);
	int ** matrixN = GenerateMatrixTask3(matrix, n);
	cout << endl;
	DisplayMatrix(matrixN, n);
	AddFile(fileName, matrixN, n);
	system("pause");
	return 0;
}