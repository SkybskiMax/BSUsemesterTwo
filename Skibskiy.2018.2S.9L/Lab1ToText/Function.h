#pragma once

int* ExtractPositiveBeforeNeg(int*, int,int&);
int CountHexSymbols(int);
void SortByHex(int*, int);


int* ExtractPositiveBeforeNeg(int *inArray, int n, int& newSize)
{
	int* tempArray = new int[n];
	for (int i = 0; i < n; ++i)
	{
		if (inArray[i] >= 0 && inArray[i] % 2 == 0 && inArray[i + 1] < 0)
		{
			tempArray[newSize] = inArray[i];
			for (int k = i; k < n; ++k)
			{
				inArray[k] = inArray[k + 1];
			}
			--n;
			++newSize;
		}
	}

	int* outArray = new int[newSize];

	for (int i = 0; i < newSize; ++i)
	{
		outArray[i] = tempArray[i];
	}
	delete[] tempArray;
	return outArray;
}

int CountHexSymbols(int number)
{
	int count = 0;
	int rest = 0;
	if (number < 0)
	{
		number *= -1;
	}
	while (number)
	{
		rest = number % 16;
		if (rest > 9 && rest < 16)
		{
			count++;
		}
		number /= 16;
	}
	return count;
}

void SortByHex(int* array, int N)
{
	bool swap = true;
	for (int k = 1; (k <= N) && swap; k++)
	{
		swap = 0;
		int temp;
		for (int j = 0; j < (N - 1); j++)
		{
			if (CountHexSymbols(array[j]) < CountHexSymbols(array[j + 1]))
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
			}
		}
	}
	return;
}

void Input(int& size)
{
	bool ok = 1;
	while (ok)
		try
	{
		std::cout << "How many numbers in array?: ";
		std::cin >> size;
		ok = 0;
		if (size <= 0)
		{
			ok = 1;
			throw std::invalid_argument("Incorrect size! Size should be greater than zero! Try again!");
		}
	}
	catch (const std::exception& exc)
	{
		std::cerr << exc.what() << std::endl;
		system("pause");
		system("cls");
	}
}