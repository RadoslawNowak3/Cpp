#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
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
static void Swap(int& a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

static int Partition(int* arr, int left, int right) {
	int x = arr[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; ++j)
	{
		if (arr[j] <= x)
		{
			++i;
			Swap(arr[i], arr[j]);
			counter++;
		}
	}

	Swap(arr[i + 1], arr[right]);
	counter++;
	return (i + 1);
}

int partition_r(int arr[], int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	counter++;
	return Partition(arr, low, high);
}
static void QuickSortIterative(int* data, int count) {
	int startIndex = 0;
	int endIndex = count - 1;
	int top = -1;
	int* stack = new int[count];

	stack[++top] = startIndex;
	stack[++top] = endIndex;

	while (top >= 0)
	{
		endIndex = stack[top--];
		startIndex = stack[top--];

		int p = partition_r(data, startIndex, endIndex);

		if (p - 1 > startIndex)
		{
			stack[++top] = startIndex;
			stack[++top] = p - 1;
			counter++;
		}

		if (p + 1 < endIndex)
		{
			stack[++top] = p + 1;
			stack[++top] = endIndex;
			counter++;
		}
	}

	delete[] stack;
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
		genR(tab, size1);
		auto start = chrono::high_resolution_clock::now();
		QuickSortIterative(tab, size1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		this_thread::sleep_for(chrono::milliseconds(1000));
		
		cerr << "Czas sortowania " << elapsed.count() << endl;
		cout << counter << endl;
		delete[] tab;
	}
}