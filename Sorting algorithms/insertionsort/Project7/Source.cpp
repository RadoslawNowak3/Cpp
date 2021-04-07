#include <iostream>
#include <thread>
#include <ctime>
long long int counter;
using namespace std;
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
	for (int i = 0; i <n; i++) {
		array[i] = 2*n-2*i;
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
	array[n - 1] = rand() % 9999 + 1;
}
void printArray(int numbers[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			counter++;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		counter++;
		arr[j + 1] = key;
	}
}
int main() {
	int z = 1;
	while (z != 0)
	{
		counter = 0;
		cout << "Wprowadz ilosc elementow tablicy" << endl;
		int size1;
		cin >> size1;
		int * tab = new int[size1];
		genSortedLast(tab, size1);
		auto start = chrono::high_resolution_clock::now();
		insertionSort(tab, size1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cerr << "Czas sortowania " << elapsed.count() << endl;
		cout << counter << endl;
		cin >> z;
		delete[] tab;
	}
}