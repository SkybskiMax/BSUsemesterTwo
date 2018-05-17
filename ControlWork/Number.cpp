#include "Number.h"
#include "FunctionExtension.h"
#include <cstring>
#include <iostream>


Number::Number(int value, int base)
{
	SetValue(value);
	SetBase(base);
	SetRepresent(value, base);
}

void Number::SetValue(int value)
{
	this->value = value;
}

void Number::SetBase(int base)
{
	this->base = base;
}

void Number::SetRepresent(int value, int base)
{
	double eps = 0.0001;
	strcpy(this->represent,convertToBase(value,base,eps));
}

void Number::SetNumber(int value, int base)
{
	SetValue(value);
	SetBase(base);
	SetRepresent(value, base);
}

void Number::DisplayNumber()
{
	std::cout << std::endl << "Value: " << this->value << std::endl << "Value in " << this->base << " base: " << this->represent;
}
