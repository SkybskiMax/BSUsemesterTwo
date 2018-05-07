#pragma once

#include <iostream>


char** CreateArrayOfWords(const char*, int&);
void DisplayArray(char**, int);
bool CheckPolindrome(char*);
void FindAllPolindrome(char**, int);



char** CreateArrayOfWords(const char* source, int& i)
{
	char** arrayOfWords = new char *[strlen(source) / 2];
	char* temp = new char[strlen(source)];
	strcpy(temp, source);
	char* pch = strtok(temp, " ,.-:;");
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

void DisplayArray(char** array, int wordCount)
{
	for (int i = 0; i < wordCount; i++)
	{
		for (int j = 0; j < strlen(array[i]); j++)
		{
			std::cout << array[i][j];
		}
		std::cout << " ";
	}
}

bool CheckPolindrome(char* word)
{
	int length = strlen(word);
	for (int i = 0; i < length / 2; i++)
	{
		if (word[i] != word[length - i - 1])
		{
			return false;
		}
	}
	return true;
}

void FindAllPolindrome(char** array, int wordCount)
{
	for (int i = 0; i < wordCount; i++)
	{
		if (CheckPolindrome(array[i]))
		{
			std::cout << array[i];
			std::cout << " ";
		}
	}
}
