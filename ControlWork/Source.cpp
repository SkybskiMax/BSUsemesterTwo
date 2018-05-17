#include <iostream>
#include "Number.h"
#include "FileExtension.h"
#pragma warning(disable:4996)

using namespace std;

int main()
{
	char InFileName[32] = "test.txt";
	char OutFileName[32] = "output.bin";
	int base;

	while (true)
	{
		cout << "Input base: ";
		cin >> base;
		if (base < 2 || base>16)
		{
			cout << "Base should be from 2 to 16! Try again!" << endl;
			system("pause");
			system("cls");
		}
		else break;
	}

	FromTextToBinary(InFileName, OutFileName,base);

	cout << "Completed! Check " << OutFileName << "!" << endl;
	DisplayFile(OutFileName);

	system("pause");
	return 0;
}