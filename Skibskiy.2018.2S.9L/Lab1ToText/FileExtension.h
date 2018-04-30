#pragma once
#include <iostream>
#include <fstream>

using namespace std;

void CreateFile(char*, int);
int ContentsFile(char*);
int* InitArray(char*, int);


void CreateFile(char* fileName, int n)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	system("cls");
	for (int i = 0; i < n; i++)
	{
		int temp = rand() % 100 - 50;
		streamOut.width(5);
		streamOut << temp;
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

