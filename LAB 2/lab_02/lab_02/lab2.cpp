#include "functions.h"
#include "lab2.h"
#include <iostream>

// Test for Questions 1 to 8

int main()
{
	std::cout << "Leapyear" << std::endl;
	if (!isLeapYear(1700))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isLeapYear(1600))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isLeapYear(2016))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "NumberReversed" << std::endl;
	if (Reversed(123) == 321)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}

	if (Reversed(1) == 1)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (Reversed(1234) != 321)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}

	std::cout << "Palindrome" << std::endl;
	if (isAPalindrome(1))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPalindrome(121))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (!isAPalindrome(1213))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "Prime Number" << std::endl;
	if (isAPrimeNumber(3))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPrimeNumber(2147483647))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (!isAPrimeNumber(4))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "Binary to Decimal" << std::endl;
	if (convertBinarytoDecimal(110) == 6)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (convertBinarytoDecimal(111) == 7)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	/*std::cout << "5 chars to int" << std::endl;
	int convertedInt = input5CharsConvertToInt();
	std::cout << convertedInt << std::endl;*/

	std::cout << "Triangles" << std::endl;
	drawRightAngledTriangle();
	drawIsocelesTriangle();

	//lab2 second part

	std::cout << "\n=== Testing Array Functions ===" << std::endl;

	// Test 1: Basic horizontal cluster
	std::cout << "\nTest 1: Horizontal cluster of 2s" << std::endl;
	int array1[4][6] = { {0,0,3,3,4,3},
						 {0,0,2,3,4,3},
						 {0,0,1,3,3,2},
						 {0,0,2,2,2,2} };
	std::cout << "Before:" << std::endl;
	PrintArray(array1);
	int score1 = ReplaceWithMinusOne(array1);
	std::cout << "After ReplaceWithMinusOne - Score: " << score1 << std::endl;
	PrintArray(array1);
	FallDownAndReplace(array1);
	std::cout << "After FallDownAndReplace:" << std::endl;
	PrintArray(array1);

	// Test 2: Vertical cluster
	std::cout << "\nTest 2: Vertical cluster of 3s" << std::endl;
	int array2[4][6] = { {0,0,3,1,3,4},
						 {0,0,3,3,4,3},
						 {0,0,3,3,3,2},
						 {0,0,1,2,2,2} };
	std::cout << "Before:" << std::endl;
	PrintArray(array2);
	int score2 = ReplaceWithMinusOne(array2);
	std::cout << "After ReplaceWithMinusOne - Score: " << score2 << std::endl;
	PrintArray(array2);
	FallDownAndReplace(array2);
	std::cout << "After FallDownAndReplace:" << std::endl;
	PrintArray(array2);

	// Test 3: Multiple columns with -1s
	std::cout << "\nTest 3: Multiple columns falling" << std::endl;
	int array3[4][6] = { {0,0,3,3,4,3},
						 {0,0,-1,3,4,3},
						 {0,0,-1,3,3,2},
						 {0,0,-1,2,3,3} };
	std::cout << "Before:" << std::endl;
	PrintArray(array3);
	FallDownAndReplace(array3);
	std::cout << "After FallDownAndReplace:" << std::endl;
	PrintArray(array3);

	// Test 4: Cluster of 4s
	std::cout << "\nTest 4: Cluster of three 4s" << std::endl;
	int array4[4][6] = { {0,0,4,4,4,3},
						 {0,0,2,3,4,3},
						 {0,0,1,3,3,2},
						 {0,0,1,1,1,1} };
	std::cout << "Before:" << std::endl;
	PrintArray(array4);
	int score4 = ReplaceWithMinusOne(array4);
	std::cout << "After ReplaceWithMinusOne - Score: " << score4 << std::endl;
	PrintArray(array4);

	std::cout << "\nPress Enter to exit...";
	std::cin.get();

	return 0;

}