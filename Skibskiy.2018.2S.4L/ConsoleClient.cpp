// ConsoleClient.cpp : Defines the entry point for the console application.
//
// Найти поэлементную разность двух матриц
#include "stdafx.h"
#include "MatrixExtension.h"
#include <iostream>

using namespace MatrixExt;
using namespace std;

int main()
{
	int n;
	cout << "Input size n of matrixes: " << endl;
	cin >> n;
	//int** matrixA = GenerateRandomMatrixInt(n, n);
	int* sizes1 = GenerateSizesMatrix(n);
	int** matrixA = GenerateJaggedMatrix(n, sizes1);
	int** matrixB = GenerateJaggedMatrix(n, sizes1);
	cout << "\tMatrix A" << endl;
	DisplayJaggedMatrix(matrixA, sizes1, n);
	cout << endl;
	cout << "\tMatrix B" << endl;
	DisplayJaggedMatrix(matrixB, sizes1, n);
	cout << endl;
	cout << "\tMatrix Difference" << endl;
	DisplayDifferenceMatrix(matrixA, matrixB, sizes1, n);
	system("pause");
	return 0;
}

