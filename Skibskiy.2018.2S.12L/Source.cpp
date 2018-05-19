#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <io.h>
#include <fstream>
#include <iostream>
#include "Film.h"


using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();

int main()
{
	char fileName[N] = "Film.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int key = Menu();
		if (key == Exit)
			return 0;
		system("cls");
		switch (key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}

	int bufSize = sizeof(Film);
	Film film;
	char ok = 'y';
	while (ok == 'y')
	{
		film.EnterFilm();
		streamOut.write((char*)&film, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> ok;
	}

	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}

	int bufSize = sizeof(Film);
	Film film;
	char Ok = 'y';
	while (Ok == 'y')
	{
		film.EnterFilm();
		streamOut.write((char*)&film, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}

	streamOut.close();
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}

	int bufSize = sizeof(Film);
	Film film;
	long position;
	InitNumber(position);
	streamInOut.seekp((position - 1) * bufSize, ios::beg);
	film.EnterFilm();
	streamInOut.write((char*)&film, bufSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}

	streamInOut.seekp(0, ios::end);
	long n = streamInOut.tellp();
	int bufSize = sizeof(Film);
	Film film;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&film, bufSize))
	{
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&film, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int diskriptorFile = open(fileName, 2);
	chsize(diskriptorFile, n - bufSize);
	close(diskriptorFile);
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}

		flag = false;
		Film filmOne, filmTwo;
		int bufSize = sizeof(Film);
		streamInOut.read((char*)&filmOne, bufSize);
		while (streamInOut.read((char*)&filmTwo, bufSize))
		{
			if (filmTwo.GetBudget() < filmOne.GetBudget())
			{
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&filmTwo, bufSize);
				streamInOut.write((char*)&filmOne, bufSize);
				flag = true;
			}
			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&filmOne, bufSize);
		}
		streamInOut.close();
	}
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}

	int bufSize = sizeof(Film);
	Film* film = new Film;

	while (streamIn.read((char*)film, bufSize))
	{
		film->DisplayFilm();
		cout << "\n";
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}