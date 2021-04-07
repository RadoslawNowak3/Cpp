#include <iostream>
#include "SortedLinkedList.h"
#include <ctime>
#include <chrono>
int main() {
	SortedLinkedList<int> a;
	int obiekt = 99;
	a.Push(obiekt);
	a.push(123);
	a.push(30);
	a.push(3);
	a.push(2);
	a.push(2);
	a.push(-1);
	a.push(56);
	a.push(128);
	a.push(128);
	a.push(128);
	a.print();
	SortedLinkedList<int>j(a);
	j.print();
	std::cout << "Rozmiar listy po stworzeniu: " << a.listSize() << std::endl;
	/* a.remove(128);
	a.print();
	std::cout << "Rozmiar listy po usunieciu wartosci 128 : " << a.listSize() << std::endl;
	*/
	a.unique();
	a.print();
	std::cout << "Rozmiar listy po usunieciu duplikatow : " << a.listSize() << std::endl;
	SortedLinkedList<int> b;
	b.push(45);
	b.push(4);
	b.push(39);
	b.push(-12);
	b.push(-12);
	b.print();
	int x=b.erase(b.find(45));
	b.print();
	SortedLinkedList<int> c = SortedLinkedList<int>::merge(a, b);
	c.print();
	std::cin >> z;
}