#include <iostream>
#include <math.h>
#include <algorithm>
#include "Stack.h"
#define N 16
#define M 16
int maxHist(int row[])
{
    Stack<int> stack;
    int last=0, maxSquare = 0, area = 0,i = 0;
    while (i < M)
    {
        if (stack.isEmpty() || row[stack.Top()] <= row[i]){
            stack.Push(i);
            ++i;
        }
        else
        {
            last = row[stack.Top()];
			stack.Pop();
			if (stack.isEmpty())
			area = last * i;
			else
                area = last * (i - stack.Top() - 1 );
            maxSquare = std::max(area, maxSquare);
        }
    }
    while (!stack.isEmpty())
    {
        last = row[stack.Top()];
        stack.Pop();
		if (stack.isEmpty())
		area = last * i;
		else
            area = last * (i - stack.Top() - 1 );

        maxSquare = std::max(area, maxSquare);
    }
    return maxSquare;
}

int maxRectangle(int A[][M])
{
    int result = maxHist(A[0]);
	std::cout << result << " ";
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)

            if (A[i][j] == 1){
                A[i][j] =A[i][j] + A[i - 1][j];
            }
        result = std::max(result, maxHist(A[i]));
		std::cout << result << " ";
		result = 0;
    }

    return result;
}


int bruteAlgorithm(int array[]) {
    int maxSquare = 0,minHeight = 0;

    for (int i = 1; i <= N; ++i)
    {
        minHeight = array[i];
        maxSquare = std::max(maxSquare, minHeight);

        for (int j = i + 1; j <= M; ++j)
        {
            minHeight = std::min(minHeight, array[j]);
            maxSquare = std::max(maxSquare, minHeight * (j - i + 1));
        }
    }
    return maxSquare;
}

int main() {
    int arr[16][16]={1 ,1 ,1 ,1 ,1 ,1, 1, 0, 1 ,1, 1 ,1, 1, 1 ,1, 1,
                         0 ,1, 0, 0, 1, 0, 1, 1, 1, 1 ,1 ,1 ,1, 1, 1, 1,
                         1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0,
                         1 ,1 ,1, 1, 1, 0, 0, 1, 1, 1, 0, 1 ,1, 1, 0, 1,
                         0 ,1 ,1, 1, 1, 1, 0, 1, 1 ,1, 1 ,1 ,1, 0, 1, 1,
                         1 ,0 ,0 ,1 ,0, 0 ,1 ,1, 1, 1, 0, 0, 0, 0, 1, 0,
                         1 ,1 ,1 ,1, 1 ,1 ,1 ,1, 1, 1, 1, 1, 1, 0, 0, 0,
                         1 ,0, 1, 1 ,1, 1 ,0 ,1, 0, 1, 1, 1, 1, 1, 1, 1,
                         1 ,1 ,1, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 0, 1, 0, 1,
                         1, 1, 1, 0, 0 ,1, 0, 1 ,0 ,1 ,1, 1, 1, 1, 1, 1,
                         1, 0, 0 ,0 ,1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1,
                         1 ,1 ,1, 0, 0 ,1, 1, 0, 1, 1, 1 ,1, 1, 1, 1, 1,
                         1, 1, 1 ,0 ,1 ,1 ,0, 1, 0, 0, 1, 1, 1, 1 ,1, 0,
                         0 ,1 ,0 ,0, 1, 1, 1, 0 ,0 ,1, 1, 1 ,1, 1 ,0, 1,
                         0 ,1 ,1 ,1 ,1 ,1 ,1, 1, 1, 0, 1, 1, 1, 0, 0, 1,
                         1 ,0 ,1, 1, 1, 0, 0 ,1 ,1 ,1, 1, 1, 1, 1, 1, 1 };
    int * countingNumbers = new int[N + 1];
    int bruteMaxSquare = 0, currentBruteMaxSquare = 0;
    for (int i = 0; i < N + 1; ++i)
    {
        countingNumbers[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 1) {
                ++countingNumbers[j + 1];
            } else {
                countingNumbers[j + 1] = 0;
            }
        }
        currentBruteMaxSquare = bruteAlgorithm(countingNumbers);
        if (currentBruteMaxSquare > bruteMaxSquare) {
            bruteMaxSquare = currentBruteMaxSquare;
        }

    }

	std::cout << "MaxSquare: "<< maxRectangle(arr) << std::endl;

	std::cout << "MaxSquare by brute " << bruteMaxSquare << std::endl;

    delete[] countingNumbers;
    return 0;
}