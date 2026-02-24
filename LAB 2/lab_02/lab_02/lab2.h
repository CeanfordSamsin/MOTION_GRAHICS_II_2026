#pragma once
#include <iostream>

// Helper function to check horizontal cluster at position
int checkHorizontal(int array[4][6], int row, int col, int value)
{
    int count = 0;
    int checkCol = col;

    // Count consecutive identical values horizontally
    while (checkCol < 6 && array[row][checkCol] == value)
    {
        count++;
        checkCol++;
    }

    return count;
}

// Helper function to check vertical cluster at position
int checkVertical(int array[4][6], int row, int col, int value)
{
    int count = 0;
    int checkRow = row;

    // Count consecutive identical values vertically
    while (checkRow < 4 && array[checkRow][col] == value)
    {
        count++;
        checkRow++;
    }

    return count;
}

// Replace horizontal cluster with -1s
void replaceHorizontalCluster(int array[4][6], int row, int col, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[row][col + i] = -1;
    }
}

// Replace vertical cluster with -1s
void replaceVerticalCluster(int array[4][6], int row, int col, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[row + i][col] = -1;
    }
}

int ReplaceWithMinusOne(int array[4][6])
{
    // Scan array from top to bottom, left to right
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            int value = array[row][col];

            // Skip if value is 0 or already marked
            if (value <= 0)
                continue;

            // Check horizontal cluster first
            int horizontalCount = checkHorizontal(array, row, col, value);
            if (horizontalCount >= 3)
            {
                int score = value * horizontalCount;
                replaceHorizontalCluster(array, row, col, horizontalCount);
                return score;
            }

            // Check vertical cluster
            int verticalCount = checkVertical(array, row, col, value);
            if (verticalCount >= 3)
            {
                int score = value * verticalCount;
                replaceVerticalCluster(array, row, col, verticalCount);
                return score;
            }
        }
    }

    return 0;
}

void FallDownAndReplace(int array[4][6])
{
    // Process each column
    for (int col = 0; col < 6; col++)
    {
        // Count -1s in this column
        int minusOneCount = 0;
        for (int row = 0; row < 4; row++)
        {
            if (array[row][col] == -1)
            {
                minusOneCount++;
            }
        }

        // If there are -1s, process this column
        if (minusOneCount > 0)
        {
            // Create temporary column storage
            int tempCol[4];
            int tempIndex = 0;

            // Collect non-minus-one values from bottom to top
            for (int row = 3; row >= 0; row--)
            {
                if (array[row][col] != -1)
                {
                    tempCol[tempIndex] = array[row][col];
                    tempIndex++;
                }
            }

            // Fill the column from bottom with collected values
            int writeRow = 3;
            for (int i = 0; i < tempIndex; i++)
            {
                array[writeRow][col] = tempCol[i];
                writeRow--;
            }

            // Fill remaining top positions with -2
            while (writeRow >= 0)
            {
                array[writeRow][col] = -2;
                writeRow--;
            }
        }
    }
}

void PrintArray(int array[4][6])
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            if (array[row][col] >= 0)
            {
                std::cout << " ";
            }
            std::cout << array[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

