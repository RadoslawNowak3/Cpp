#include <iostream>
#include <ctime>
#include <thread>
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
		cout << numbers[i] << " ";
	}
	cout << endl;
}

class Heap {
private:
	void heapifyIter(int);
	int * elements;
	int elements_number;
	int capacity;
public:
	Heap(int capacity);
	void build(int[], int);
	void push(int x);           
	int pop();                  
	int& top();                
	int size();                
	bool empty();               
	bool check();               
	void printArray();
	void sortIter(int[], int);
};
void Heap::heapifyIter(int index)
{
	int largest_index = index;
	bool loop_flag;
	do
	{
		loop_flag = false;
		if (2 * index + 1 < elements_number && elements[2 * index + 1] > elements[largest_index])
		{
			largest_index = 2 * index + 1;
		}
		if (2 * index + 2 < elements_number && elements[2 * index + 2] > elements[largest_index])
		{
			largest_index = 2 * index + 2;
		}
		if (largest_index != index)
		{
			std::swap(elements[largest_index], elements[index]);
			counter++;
			index = largest_index;
			loop_flag = true;
		}
	} while (loop_flag);
}

Heap::Heap(int capacity)
{
	elements = new int[capacity];
	elements_number = 0;
	this->capacity = capacity;
}

void Heap::build(int array[], int size)
{
	delete[] elements;
	elements = new int[size];
	for (int i = 0; i < size; i++)
	{
		elements[i] = array[i];
	}
	capacity = size;
	elements_number = size;

	for (int i = elements_number / 2 - 1; i >= 0; --i)
	{
		heapifyIter(i);
	}
}

void Heap::push(int x)
{
	if (elements_number == capacity)
	{
		throw std::out_of_range("Heap is full");
	}
	else
	{
		int child_index = elements_number;
		int parent_index = (elements_number - 1) / 2;
		while (child_index > 0 && elements[parent_index] < x)
		{
			elements[child_index] = elements[parent_index];
			child_index = parent_index;
			parent_index = (child_index - 1) / 2;
		}

		elements[child_index] = x;
		++elements_number;
	}
}

int Heap::pop()
{
	if (elements_number == 0)
	{
		throw out_of_range("Heap is empty");
	}
	else
	{
		int last_element = elements[elements_number - 1];
		int return_val = elements[0];

		int parent_index = 0;
		int child_index = 1;

		while (child_index < elements_number - 1)
		{
			if (child_index + 1 < elements_number - 1 && elements[child_index + 1] > elements[child_index]) 
			{
				++child_index;
			}

			if (last_element >= elements[child_index])
			{
				break;
			}

			elements[parent_index] = elements[child_index];
			parent_index = child_index;
			child_index = 2 * child_index + 1;
		}

		elements[parent_index] = last_element;
		--elements_number;

		return return_val;
	}
}

int & Heap::top()
{
	if (elements_number == 0)
	{
		throw std::out_of_range("Heap is empty");
	}
	else
	{
		return elements[0];
	}
}

int Heap::size()
{
	return elements_number;
}

bool Heap::empty()
{
	return elements_number == 0;
}

bool Heap::check()
{
	for (int i = elements_number - 1; i >= 1; --i)
	{
		int parent_index = (i - 1) / 2;
		if (elements[i] > elements[parent_index])
		{
			return false;
		}
	}
	return true;
}

void Heap::sortIter(int array[], int size)
{
	build(array, size);

	for (int i = elements_number - 1; i >= 0; --i)
	{
		swap(elements[0], elements[i]);
		counter++;
		--elements_number;
		heapifyIter(0);
	}
}

void Heap::printArray()
{
	for (int i = 0; i < capacity; i++)
	{
	cout << elements[i] << " ";
	}
	cout << endl;
}

int main() {
	int z = 1;
	while (z != 0)
	{
		counter = 0;
		cout << "Wprowadz ilosc elementow tablicy" << endl;
		int size1;
		cin >> size1;
		Heap heap(size1);
		int * tab = new int[size1];
		genSortedLast(tab, size1);
		auto start = chrono::high_resolution_clock::now();
		heap.sortIter(tab, size1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cerr << "Czas sortowania " << elapsed.count() << endl;
		cout << counter << endl;
		delete[] tab;
	}
}