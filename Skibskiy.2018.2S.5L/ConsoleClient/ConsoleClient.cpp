#include "stdafx.h"
#include "StiringExtension.h"


int main()
{
	int i = 0;
	const char string[256] = "Hello baab world! salas woow This is test";
	char** arrayWords=CreateArrayOfWords(string, i);
	DisplayArray(arrayWords, i);
	std::cout << "\nAll polindromes: \n";
	FindAllPolindrome(arrayWords, i);
	system("pause");
    return 0;
}

