#pragma once
#define _CRT_NONSTDC_NO_DEPRECATE
const int N = 256;

struct Director
{
	char firstName[N]{};
	char lastName[N]{};
};

class Film
{
public:
	Film() {}
	Film(char*, char*, char*, char*, char*, int, int);
	~Film() {}
	void SetDirectorFirstName(char*);
	void SetDirectorLastName(char*);
	void SetTitle(char*);
	void SetCountry(char*);
	void SetRelease(char*);
	void SetBudget(int);
	void SetIncome(int);
	void SetProfit(int,int);
	void SetFilm(char*, char*, char*, char*, char*, int, int);
	char* GetDirectorFirstName();
	char* GetDirectorLastName();
	char* GetTitle();
	char* GetCountry();
	char* GetRelease();
	int GetBudget();
	int GetIncome();
	void EnterFilm();
	void DisplayFilm();
private:
	Director director;
	char title[N]{}, country[N]{}, release[N]{};
	int budget, income, profit;
};