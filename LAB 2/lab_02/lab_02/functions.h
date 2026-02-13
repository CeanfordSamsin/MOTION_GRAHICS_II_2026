#pragma once
#include <iostream>

bool isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		else 
		{
			return true;
		}
	}
	else 
	{
		return false;
	}
	return true;
}

int Reversed(int testNumber)
{
	return 0;
}
bool isAPalindrome(int testNumber)
{
	int original = testNumber;
	int reversed = 0;

	//handle negative numbers as not palindromes
	if (testNumber < 0)
	{
		return false;
	}

	while (testNumber > 0)
	{
		int digit = testNumber % 10;
		reversed = reversed * 10 + digit;
		testNumber = testNumber / 10;
	}

	return original == reversed;
	
}

bool isAPrimeNumber(int numbertoTest)
{
	if (numbertoTest <= 1)
	{
		return false;
	}

	for(int i = 2; i * i <= numbertoTest; i++)
	{
		if (numbertoTest % i == 0)
		{
			return false;
		}
	}
	return true;
}

int input5CharsConvertToInt()
{
	int returnInt = 0;
	char inputChar;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> inputChar;
		//check if its a digit.
		//do something
		if (inputChar < '0' || inputChar > '9')
		{
			return 0;
		}
		returnInt = returnInt * 10 + (inputChar - '0');

	}
	return returnInt;
}
int convertBinarytoDecimal(int binaryNumber)
{
	int decimalNumber = 0;
	int base = 1;

	while (binaryNumber > 0)
	{
		int lastDigit = binaryNumber % 10;
		decimalNumber = decimalNumber + lastDigit * base;
		base = base * 2;
		binaryNumber = binaryNumber / 10;
	}

	return decimalNumber;
}
void drawRightAngledTriangle()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;
	}

}
void drawIsocelesTriangle()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (j <= 6 - i)
			{
				std::cout << '*';
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

}
void drawIsocelesTriangle2()
{

}

int find(int size, int arr[], int toFind)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == toFind)
		{
			std::cout << i << std::endl;
			return -1;
		}
	}
	std::cout << -1 << std::endl;
	return -1;
}
int find2ndLargest(int size, int arr[])
{
	if (size < 2)
	{
		return -1;
	}

	int largest = -1;
	int secondLargest = -1;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > largest)
		{
			secondLargest = largest;
			largest = arr[i];
		}
		else if (arr[i] > secondLargest && arr[i] < largest)
		{
			secondLargest = arr[i];
		}
	}
	return secondLargest;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr1[i];
	}
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{
	if (count >= size || insertIndex < 0 || insertIndex > count)
	{
		return false;
	}

	for (int i = count; i > insertIndex; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[insertIndex] = elementToInsert;
	count++;
	return true;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{

	return true;
}
int frequencyCount(int size, int arr[], int value)
{

	return 0;
}
int countDuplicates(int size, int arr[])
{

	return 0;
}
void reverse(int size, int arr[])
{
	return;
}
int rotateLeft(int size, int arr[])
{
	return -1;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	return false;
}
int wordCounter(int size, char characters[])
{
	return 0;
}