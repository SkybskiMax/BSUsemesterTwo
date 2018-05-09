#pragma once
#include <iostream>
#include <fstream>
#include "StringExtension.h"

using namespace std;

void CreateFile(char*, char*, int);
int ContentsFile(char*);
int* InitArray(char*, int);
char* InitCharArray(char*, int);
void AddFile(char*, int*, int);
int CountFileSymbols(char*);



void CreateFile(char* fileName, char* string, int wordCount)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}
	system("cls");

	char** arrayWords = CreateArrayOfWords(string, wordCount);
	streamOut << "Polindromes: ";
	for (int i = 0; i < wordCount; i++)
	{
		if (CheckPolindrome(arrayWords[i]))
		{
			streamOut << arrayWords[i];
			streamOut << " ";
		}
	}

	streamOut.close();
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0, temp;

	while (!streamIn.eof())
	{
		streamIn >> temp;
		count++;
	}

	streamIn.close();
	return count;
}

char* TextFromFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = CountFileSymbols(fileName);
	char* string = new char[count];
	streamIn.getline(string, 256);

	streamIn.close();
	return string;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		streamIn >> array[i];
	}

	streamIn.close();
	return array;
}

char* InitCharArray(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	char* array = new char;
	for (int i = 0; i < n; i++)
	{
		streamIn >> array[i];
	}

	streamIn.close();
	return array;
}

void AddFile(char* fileName, int* array, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted array!\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << array[i];
	}
	streamOut.close();
}

int CountFileSymbols(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0;
	char temp;

	while (!streamIn.eof())
	{
		streamIn >> temp;
		count++;
	}

	streamIn.close();
	return count;
}
