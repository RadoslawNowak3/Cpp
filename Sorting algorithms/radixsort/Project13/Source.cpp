#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <thread>
#include <math.h>
#include <stdio.h>
#include "queue.h"
using namespace std;
long long int counter;
void genRandom(int A[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		A[i] = rand() % 9999 + 1;
	}
}
void genSorted(int array[], int n) {
	array[0] = 1;
	for (int i = 1; i < n; ++i) {
		array[i] = 2 * i + 1;
	}
}
void genReverse(int array[], int n) {
	for (int i = 0; i < n; i ++) {
		array[i] = n-i;
	}
}
void genSortedFirst(int array[], int n) {
	srand(time(NULL));
	array[0] = rand() % 9999 + 1;
	for (int i = 1; i < n; ++i) {
		array[i] = 2 * i + 1;
	}
}
void genSortedLast(int array[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		array[i] = 2 * i + 1;
	}
	array[n - 1] = rand() % 9999999 + 1;
}
void printArray(int numbers[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int z = 0;
	while (z == 0)
	{
		counter = 0;
		int n, i, j, maxValue = 0;
		cout << "Podaj liczbe elementow do posortowania: " << endl;
		cin >> n;
		int *tab = new int[n];
		genRandom(tab, n);
		for (i = 0; i < n; i++) {
			maxValue = max(tab[i], maxValue);
		}
		auto *queues = new queue[10];
		for (i = 0; i < 10; i++) {
			queues[i] = new queue;
		}
		int div = 1;
		int temp = 10;
		auto start = chrono::high_resolution_clock::now();
		while (maxValue > div) {
			for (j = 0; j < n; j++) {
				queues[(int)floor((tab[j] % temp) / div)].push(tab[j]);
			}
			j = 0;
			for (i = 0; i < 10; i++) {
				while (!queues[i].isEmpty()) {
					counter++;
					tab[j] = queues[i].pop();
					j++;
				}
			}
			temp *= 10;
			div *= 10;
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		cerr << "Elapsed time[s] = " << elapsed.count() << endl;
		cout << "Counter: " << counter << endl;
		delete[] tab;
	}
	return 0;
}