#include <iostream>
#include "Function.h"
#include "FileExtension.h"

using namespace std;

int main()
{
	char fileName[20] = "array.txt";
	int size=1;
	int newSize = 0;

	Input(size);

	CreateFile(fileName, size);
	int* inArray = InitArray(fileName, size);
	int* outArray = ExtractPositiveBeforeNeg(inArray,size, newSize);
	SortByHex(outArray, newSize);
	AddFile(fileName, outArray, newSize);

	cout << "Completed! Check " << fileName << "!" << endl;

	system("pause");
}

