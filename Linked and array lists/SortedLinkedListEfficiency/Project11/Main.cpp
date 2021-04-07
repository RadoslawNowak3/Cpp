#include <iostream>
#include "SortedLinkedList.h"
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

int main() {
	cout << "Wprowadz ilosc elementow listy" << endl;
	int size1, number, z;
	cin >> size1;
	srand(time(NULL));
	SortedLinkedList<int> a;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < size1; i++) {
		number = rand() % 99999 + 1;
		a.push(number);
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cerr << "Czas dodawania " << elapsed.count() << endl;
	int size = a.size;
	auto start2 = chrono::high_resolution_clock::now();
	while (size > 0) {
		auto it = a.begin();
		int pos = rand() % size;
		for (int i = 0; i < pos; i++)
			it++;
		a.erase(it);
		size--;
	}
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed2 = end2 - start2;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cerr << "Czas usuwania  " << elapsed2.count() << endl;
	a.print();
	cin >> z;
}