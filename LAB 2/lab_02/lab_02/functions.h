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
}

int Reversed(int testNumber)
{
	int reversed = 0;

	while (testNumber > 0)
	{
		int digit = testNumber % 10;
		reversed = reversed * 10 + digit;
		testNumber = testNumber / 10;
	}

	return reversed;
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
	if (numbertoTest == 2)
	{
		return true;
	}
	if (numbertoTest % 2 == 0)
	{
		return false;
	}

	// Check odd divisors up to sqrt(numbertoTest)
	// Rewrite i * i <= numbertoTest as i <= numbertoTest / i to avoid overflow
	for (int i = 3; i <= numbertoTest / i; i += 2)
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
	for (int i = 1; i <= 5; i++)
	{
		// Print leading spaces
		for (int j = 1; j <= 5 - i; j++)
		{
			std::cout << ' ';
		}
		// Print stars
		for (int k = 1; k <= 2 * i - 1; k++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;
	}
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
	// Check if index is valid and array has elements
	if (deleteIndex < 0 || deleteIndex >= count || count <= 0)
		return false;

	// Shift elements to the left
	for (int i = deleteIndex; i < count - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	count--;
	return true;
}
int frequencyCount(int size, int arr[], int value)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			count++;
		}
	}
	return count;
}
int countDuplicates(int size, int arr[])
{
	int duplicateCount = 0;

	for (int i = 0; i < size; i++)
	{
		// Check if this element has already been counted as a duplicate
		int alreadyCounted = 0;
		for (int k = 0; k < i; k++)
		{
			if (arr[k] == arr[i])
			{
				alreadyCounted = 1;
				break;
			}
		}

		if (alreadyCounted == 1)
			continue;

		// Count occurrences of arr[i]
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[j] == arr[i])
			{
				count++;
			}
		}

		// If count > 1, it's a duplicate
		if (count > 1)
		{
			duplicateCount++;
		}
	}

	return duplicateCount;
}
void reverse(int size, int arr[])
{
	int start = 0;
	int end = size - 1;

	while (start < end)
	{
		// Swap elements
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++;
		end--;
	}
}
int rotateLeft(int size, int arr[])
{
	if (size <= 0)
		return -1;

	int firstElement = arr[0];

	// Shift all elements one position to the left
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	// Place the first element at the end
	arr[size - 1] = firstElement;

	return 0;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	// Check all pairs of movies
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (movieLengths[i] + movieLengths[j] == flightLength)
			{
				return true;
			}
		}
	}
	return false;
}
int wordCounter(int size, char characters[])
{
	int wordCount = 0;
	int inWord = 0; // 0 = not in a word, 1 = currently in a word

	for (int i = 0; i < size; i++)
	{
		// Check if current character is alphabetic
		if ((characters[i] >= 'A' && characters[i] <= 'Z') ||
			(characters[i] >= 'a' && characters[i] <= 'z'))
		{
			if (inWord == 0)
			{
				// Starting a new word
				wordCount++;
				inWord = 1;
			}
		}
		else
		{
			// Non-alphabetic character, not in a word anymore
			inWord = 0;
		}
	}

	return wordCount;
}