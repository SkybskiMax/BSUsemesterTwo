#include "FileExtension.h"
#include "StringExtension.h"
#pragma warning(disable:4996)

int main()
{
	char InFileName[32]="input.txt";
	char OutFileName[32] = "output.txt";
	char* string{};
	int i = 0;

	string = TextFromFile(InFileName);
	CreateFile(OutFileName, string,i);
	cout << "Completed! Check " << OutFileName << "!" << endl;

	system("pause");
	return 0;
}