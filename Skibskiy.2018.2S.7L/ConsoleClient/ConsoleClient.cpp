#include "stdafx.h"
#include <iostream>
#include "EquationExtension.h"

using namespace std;

int main()
{
	double guess;
	double eps;
	Input(guess, eps);
    AdvancedNewtonMethod(guess, eps);
	cout << endl;
	SecantMethod(guess, eps);
	system("pause");
    return 0;
}

