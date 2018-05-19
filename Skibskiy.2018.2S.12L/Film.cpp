#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include "Film.h"


using namespace std;

Film::Film(char* title, char* directorFirstName, char* directorLastName, char* country, char* release, int budget, int income)
{
	this->SetFilm(title, directorFirstName, directorLastName, country, release, budget, income);
}

void Film::SetTitle(char* title)
{
	strcpy(this->title, title);
}

void Film::SetDirectorFirstName(char* firstName)
{
	strcpy(this->director.firstName, firstName);
}

void Film::SetDirectorLastName(char* lastName)
{
	strcpy(this->director.lastName, lastName);
}

void Film::SetCountry(char* country)
{
	strcpy(this->country, country);
}

void Film::SetRelease(char* release)
{
	strcpy(this->release, release);
}

void Film::SetBudget(int budget)
{
	this->budget = budget;
}

void Film::SetIncome(int income)
{
	this->income = income;
}

void Film::SetProfit(int budget, int income)
{
	this->profit = income - budget;
}

char* Film::GetDirectorFirstName()
{
	return this->director.firstName;
}

char* Film::GetDirectorLastName()
{
	return this->director.lastName;
}

char* Film::GetTitle()
{
	return this->title;
}

char* Film::GetCountry()
{
	return this->country;
}

char* Film::GetRelease()
{
	return this->release;
}

int Film::GetBudget()
{
	return this->budget;
}

int Film::GetIncome()
{
	return this->income;
}

void Film::SetFilm(char* title, char* directorFirstName, char* directorLastName, char* country, char* release, int budget, int income)
{
	this->SetDirectorFirstName(directorFirstName);
	this->SetDirectorLastName(directorLastName);
	this->SetTitle(title);
	this->SetCountry(country);
	this->SetRelease(release);
	this->SetBudget(budget);
	this->SetIncome(income);
	this->SetProfit(budget, income);
}

void Film::DisplayFilm()
{
	cout << endl << this->title << " " << "by " << this->director.firstName << " " << this->director.lastName << endl;
	cout << "Made in " << this->country << ", released in " << this->release << "." << endl << "Budget: " <<this->budget<< ", Income : " << this->income << ", Profit : " << this->profit;
}

void Film::EnterFilm()
{
	const int N = 256;
	char title[N] = "", directorFirstName[N] = "", directorLastName[N] = "", country[N] = "", release[N] = "";
	int budget, income;

	cout << "Enter title of film:";
	cin.ignore();
	cin.getline(title, N, '\n');
	cout << "Enter director's first name:";
	cin.getline(directorFirstName, N, '\n');
	cout << "Enter director's last name:";
	cin.getline(directorLastName, N, '\n');
	cout << "Enter country:";
	cin.getline(country, N, '\n');
	cout << "Enter release date:";
	cin.getline(release, N, '\n');
	cout << "Enter budget:";
	cin >> budget;
	cout << "Enter income:";
	cin >> income;

	this->SetFilm(title, directorFirstName, directorLastName, country, release, budget, income);
}
