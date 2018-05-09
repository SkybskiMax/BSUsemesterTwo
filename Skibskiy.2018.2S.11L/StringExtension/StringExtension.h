#pragma once

#include <iostream>


char** CreateArrayOfWords(const char*, int&);


char ** CreateArrayOfWords(const char * source, int & i)
{
	char ** arrayOfWords = new char *[strlen(source) / 2];
	char * temp = new char[strlen(source)];
	strcpy(temp, source);
	char  * pch = strtok(temp, " ,.-:;");
	i = 0;

	while (pch != nullptr)
	{
		arrayOfWords[i] = new char[strlen(pch) + 1];
		strcpy(arrayOfWords[i], pch);
		pch = strtok(nullptr, " ,.-:;");
		i++;
	}
	return arrayOfWords;
}

