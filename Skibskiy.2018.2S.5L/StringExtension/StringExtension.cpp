// StringExtension.cpp : Defines the exported functions for the DLL application.
//
//Рассортировать слова англоязычного текста по возрастанию в них доли гласных букв 
//(отношение количества гласных букв к общему количеству букв в слове).
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "StringExtension.h"
using namespace std;

STRINGEXTENSION_API char** StringExt::StrCreateArrayOfWords(const char* source, int& i)
{
	char** MatrixOfWords = new char*[strlen(source) / 2];
	int len = 0;
	char* str;
	int wordCounter = 0;
	char sep[10] = ",!?;: ";
	while (*str != '\0')
	{
		str += strspn(str, sep);
		len = strcspn(str, sep);
		char *word = new char[len];
		strncpy(word, str, len);
		word[len] = '\0';
		MatrixOfWords[wordCounter] = word;
		wordCounter++;
		str += strcspn(str, sep);
	}
}
