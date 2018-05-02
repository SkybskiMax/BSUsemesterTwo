#pragma once
#include <iostream>
#include <cmath>

#pragma region Prototypes
double Function(double, int);
double Derivative(double);
double DoubleDerivative(double);
void AdvancedNewtonMethod(double, double);
void SecantMethod(double, double);
void Input(double&, double&);
#pragma endregion

#pragma region Functions
inline double Function(double x, int alpha)
{
	return exp(1.0 / x) - (x + 1)*(x + 1) + alpha;
}

inline double Derivative(double x)
{
	return -exp(1.0 / x) / x / x - 2 * (x + 1);
}

inline double DoubleDerivative(double x)
{
	return (exp(1 / x)*(2 * x + 1) / pow(x, 4)) - 2;
}

void AdvancedNewtonMethod(double previous, double eps)
{
	double temp = previous;
	std::cout << "\tEquation\t\t\t" << "Root (AdvancedNewtonMethod)" << std::endl;
	for (int alpha = 1; alpha < 5; alpha++)
	{
		previous = temp;
		double following = previous - (Function(previous, alpha) / Derivative(previous)) - (DoubleDerivative(previous)*Function(previous, alpha)*Function(previous, alpha)) / (2 * pow(Derivative(previous), 2));
		for (; (fabs(previous - following) >= eps);)
		{
			previous = following;
			following = previous - (Function(previous, alpha) / Derivative(previous)) - (DoubleDerivative(previous)*Function(previous, alpha)*Function(previous, alpha)) / (2 * pow(Derivative(previous), 2));
		}
		std::cout << "exp(1.0 / x) - (x + 1)*(x + 1) + " << alpha << "\t\t" << following << std::endl;
	}
}

void SecantMethod(double previous, double eps)
{
	double tempPrevious = previous;
	double tempCurrent = previous+1;
	double current = previous;
	std::cout << "\tEquation\t\t\t" << "Root (SecantMethod)" << std::endl;
	for (int alpha = 1; alpha < 5; alpha++)
	{
		current = tempCurrent;
		previous = tempPrevious;
		double following = current - (current - previous)*Function(current, alpha) / (Function(current, alpha) - Function(previous, alpha));
		for (; (fabs(following - current) >= eps);)
		{
			previous = current;
			current = following;
			following = current - (current - previous)*Function(current, alpha) / (Function(current, alpha) - Function(previous, alpha));
		}
		std::cout << "exp(1.0 / x) - (x + 1)*(x + 1) + " << alpha << "\t\t" << following << std::endl;
	}
}
#pragma endregion

void Input(double& guess, double& eps)
{
	bool ok = 1;
	while (ok)
	try
	{
		std::cout << "Input guess: ";
		std::cin >> guess;
		std::cout << "Input eps: ";
		std::cin >> eps;
		ok = 0;
		if (eps <= 0 || eps >= 1)
		{
			ok = 1;
			throw std::invalid_argument("Incorrect epsilon! Epsilon should be from 0 to 1! Try again!");
		}
	}
	catch (const std::exception& exc)
	{
		std::cerr << exc.what() << std::endl;
		system("pause");
		system("cls");
	}
}