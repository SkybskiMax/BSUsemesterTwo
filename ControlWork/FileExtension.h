#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>


using namespace std;

void FromTextToBinary(char*, char*, int);
int ContentsFile(char*);
char* InitCharArray(char*, int);
void AddFile(char*, int*, int);
int CountFileSymbols(char*);
void AddToBinaryFile(char*, int, int);



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

void FromTextToBinary(char* fileName, char* binaryName, int base)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int value;
	while (!streamIn.eof())
	{
		streamIn >> value;
		if (value > 0)
		{
			AddToBinaryFile(binaryName, value, base);
		}
	}

	streamIn.close();
	return;
}

void AddToBinaryFile(char* fileName, int value, int base)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary | ios::app);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		return;
	}

	int bufSize = sizeof(Number);
	Number number;
	number.SetNumber(value, base);
	streamOut.write((char*)&number, bufSize);

	streamOut.close();
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

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		return;
	}

	int bufSize = sizeof(Number);
	Number* number = new Number;

	while (streamIn.read((char*)number, bufSize))
	{
		number->DisplayNumber();
		cout << "\n";
	}
	streamIn.close();
}