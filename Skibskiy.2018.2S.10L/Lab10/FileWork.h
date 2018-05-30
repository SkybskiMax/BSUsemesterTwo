#pragma once
#include <iostream>
#include <fstream>

int ContentsFile(char*);
int** InitMatrix(char*, int);
void AddFile(char*, int**, int);

using namespace std;

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int** InitMatrix(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamIn >> matrix[i][j];
		}
	}

	streamIn.close();
	return matrix;
}

void AddFile(char* fileName, int** arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << "\nNew matrix!\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamOut.width(4);
			streamOut << arr[i][j];
		}
		streamOut << endl;
	}

	streamOut.close();
}