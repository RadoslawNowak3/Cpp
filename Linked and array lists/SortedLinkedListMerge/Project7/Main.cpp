#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include "SortedLinkedList.h"

using namespace std;
void noDuplicates()
{
	int size1, size2;
	cout << "Wprowadz rozmiar pierwszej listy" << endl;
	cin >> size1;
	cout << "Wprowadz rozmiar drugiej listy" << endl;
	cin >> size2;
	SortedLinkedList<int> a;
	srand(time(NULL));
	for (int i = 0; i < size1; i++) {
		a.push(rand() % 99999 + 1);
	}
	SortedLinkedList<int> b;
	for (int i = 0; i < size2; i++) {
		b.push(rand() % 99999 + 1);
	}
	auto start = chrono::high_resolution_clock::now();
	SortedLinkedList<int> c = SortedLinkedList<int>::merge(a, b);
	c.unique();
	c.print();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cerr << "Elapsed time[s] = " << elapsed.count() << endl;
}
void Duplicates()
{
	int size1, size2;
	cout << "Wprowadz rozmiar pierwszej listy" << endl;
	cin >> size1;
	cout << "Wprowadz rozmiar drugiej listy" << endl;
	cin >> size2;
	srand(time(NULL));
	SortedLinkedList<int> a;
	for (int i = 0; i < size1; i++) {
		a.push(rand() % 99999 + 1);
	}
	SortedLinkedList<int> b;
	for (int i = 0; i < size2; i++) {
		b.push(rand() % 99999 + 1);
	}
	auto start = chrono::high_resolution_clock::now();
	SortedLinkedList<int> c = SortedLinkedList<int>::merge(a, b);
	c.print();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cerr << "Elapsed time[s] = " << elapsed.count() << endl;
}
int main() {
	cout << "Wybierz co chcesz zrobic: " << endl;
	cout << "Nacisnij 1 jesli chcesz wypisac liste bez powtorzen" << endl;
	cout << "Nacisnij 2 jesli chcesz wypisac liste z powtorzeniami" << endl;
	int choice;
	cin >> choice;
	int a;
	switch (choice)
	{
	case 1:
		noDuplicates();
		cin >> a;
		break;
	case 2:
		Duplicates();
		cin >> a;
		break;
	default:
		cout << "Zly wybor " << endl;
	}

	return 0;
}