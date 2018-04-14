#pragma once

#ifdef MATRIXEXTENSION_EXPORTS
#define MATRIXEXTENSION_API __declspec(dllexport) 
#else
#define MATRIXEXTENSION_API __declspec(dllimport) 
#endif

namespace MatrixExt
{
	MATRIXEXTENSION_API int** GenerateRandomMatrixInt(int, int);
	MATRIXEXTENSION_API double** GenerateRandomMatrix(int, int);
	MATRIXEXTENSION_API double** GenerateRandomSymmMatrix(int, int);
	MATRIXEXTENSION_API double** GenerateTaylorMatrix(int, int);
	MATRIXEXTENSION_API double** GenerateMatrix(int, int);
	MATRIXEXTENSION_API int** GenerateJaggedMatrix(int, int*);
	MATRIXEXTENSION_API int* GenerateSizesMatrix(int);
	MATRIXEXTENSION_API double** GenerateMatrixTask11(double**, int, int);
	MATRIXEXTENSION_API double** AllocateMemory(int, int);
	MATRIXEXTENSION_API int** AllocateMemoryInt(int, int);
	MATRIXEXTENSION_API void FreeMemory(int**, int);
	MATRIXEXTENSION_API void FreeMemory(bool**, int);
	MATRIXEXTENSION_API void FillRandomMatrix(double**, int, int);
	MATRIXEXTENSION_API void FillRandomMatrix(int**, int, int);
	MATRIXEXTENSION_API void FillRandomSymmMatrix(double**, int, int);
	MATRIXEXTENSION_API void FillTaylorMatrix(double**, int, int);
	MATRIXEXTENSION_API void FillMatrix(double**, int, int);
	MATRIXEXTENSION_API void DisplayMatrix(double**, int, int);
	MATRIXEXTENSION_API void DisplayMatrix(bool**, int, int);
	MATRIXEXTENSION_API void DisplayMatrix(int**, int, int);
	MATRIXEXTENSION_API void DisplayDifferenceMatrix(int**,int**,int*, int);
	MATRIXEXTENSION_API void DisplayJaggedMatrix(int**, int*, int);
	MATRIXEXTENSION_API double SinTaylor(double, double);
	MATRIXEXTENSION_API double CosTaylor(double, double);
	MATRIXEXTENSION_API double CompareMatrix(double**, double**, int, int);
	MATRIXEXTENSION_API double FindMaxElementInScope(double**, int, int, int);
}
