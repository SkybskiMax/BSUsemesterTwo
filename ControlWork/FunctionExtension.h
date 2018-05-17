#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>

char conversionIntToChar(int);
void transFracPar(int, int, char);
void strCopy(char[], char[], int, int);
int strGetLength(char[]);
void strSwap(char & a, char & b);
char* convertToBase(int &number, int base, int accuracy);

char conversionIntToChar(int temp)
{
	char symbol;
	switch (temp)
	{
	case 1:
		symbol = '1';
		break;
	case 2:
		symbol = '2';
		break;
	case 3:
		symbol = '3';
		break;
	case 4:
		symbol = '4';
		break;
	case 5:
		symbol = '5';
		break;
	case 6:
		symbol = '6';
		break;
	case 7:
		symbol = '7';
		break;
	case 8:
		symbol = '8';
		break;
	case 9:
		symbol = '9';
		break;
	case 0:
		symbol = '0';
		break;
	case 10:
		symbol = 'A';
		break;
	case 11:
		symbol = 'B';
		break;
	case 12:
		symbol = 'C';
		break;
	case 13:
		symbol = 'D';
		break;
	case 14:
		symbol = 'E';
		break;
	case 15:
		symbol = 'F';
		break;
	}
	return symbol;
}

void transFracPar(int intPart, int base, char intPartString[])
{
	for (int i = 0; intPart; i++)
	{
		intPartString[i] = conversionIntToChar(intPart%base);
		intPart /= base;
	}
}

void strCopy(char source[], char destination[], int from, int to)
{
	if (from < 0) from = 0;
	if (to > strGetLength(source)) to = strGetLength(source);

	for (int i = from, j = 0; i < to; i++, j++)
	{
		destination[j] = source[i];
	}
}

int strGetLength(char arr[])
{
	int i = 0;
	while (arr[i])
	{
		i++;
	}
	return i;
}

void strSwap(char & a, char & b)
{
	char temp = a;
	a = b;
	b = temp;
}

void strReverse(char * source)
{
	int length = strGetLength(source);
	for (int i = 0; i < length / 2; i++)
	{
		strSwap(source[i], source[length - 1 - i]);
	}
}

char* convertToBase(int &number, int base, int accuracy)
{
	char intPartString[32]="";
	char result[32];

	transFracPar(number, base, intPartString);
	strReverse(intPartString);

	char* intString = intPartString;
	//intPartString --- итог
	strcpy(result, intString);
	return result;
}