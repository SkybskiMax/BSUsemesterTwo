#pragma once

class Number
{
public:
	Number(){}
	Number(int, int);
	void SetValue(int);
	void SetBase(int);
	void SetRepresent(int, int);
	void SetNumber(int, int);
	void DisplayNumber();
private:
	int value;
	int base;
	char represent[32];
};