#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
using namespace std;
int * aux;
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
	for (int i = 0; i < n; i++) {
		array[i] = n - i;
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

void bitmerge(int a[], int l, int m, int r)
{
	int i, j;
	for (i = 0; i <= m; i++)
	{
		aux[i] = a[i];
	}
	for (j = m + 1; j <= r; j++)
	{
		aux[r + m + 1 - j] = a[j];
	}
	i = l;
	j = r;
	for (int k = l; k <= r; k++) {
		if (aux[j] < aux[i])
		{ a[k] = aux[j]; 
		counter++;
		j = j - 1;
		}
		else
		{	
			a[k] = aux[i]; i = i + 1;
			counter++;
		}
	}
}
void bitsort(int a[], int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;
		bitsort(a, l, m);
		bitsort(a, m + 1, r);
		bitmerge(a, l, m, r);
	}
}
/*
void Swap(int a[], int i, int j, int dir)
{
	if (dir == (a[i] > a[j]))
	{
		swap(a[i], a[j]);
		counter++;
	}
}

void bitonicMerge(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
			Swap(a, i, i + k, dir);
		bitonicMerge(a, low, k, dir);
		bitonicMerge(a, low + k, k, dir);
	}
}

void bitonicSort(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		bitonicSort(a, low, k, 1);
 
		bitonicSort(a, low + k, k, 0);

		bitonicMerge(a, low, cnt, dir);
	}
}
*/
int main() {
	
	int z = 1;
	while (z != 0)
	{
		counter = 0;
		cout << "Wprowadz ilosc elementow tablicy" << endl;
		int size1;
		cin >> size1;
		aux = new int[size1];
		int * tab = new int[size1];
		genSortedLast(tab, size1);
		auto start = chrono::high_resolution_clock::now();
		bitsort(tab,0,size1-1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cerr << "Czas sortowania " << elapsed.count() << endl;
		cout << counter << endl;
	}
}