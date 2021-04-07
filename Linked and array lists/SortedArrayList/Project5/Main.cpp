#include <iostream>
#include "SortedArrayList.h"
int main()
{
	SortedArrayList<int> a;
	a.push(10);
	a.push(50);
	a.push(0);
	std::cout << "Rozmiar listy po stworzeniu: " << a.size() << std::endl;
	a.print();
	a.erase(a.find(10));
	std::cout << "Rozmiar listy: " << a.size() << std::endl;
	a.print();
	a.push(5);
	a.pop();
	a.print(); 
	SortedArrayList<int>x(a);
	x.print();
	SortedArrayList<int>c;
	c.push(5);
	c.push(5);
	c.push(2);
	c.push(6);
	SortedArrayList<int>d = SortedArrayList<int>::merge(a, c);
	d.print();
	d.unique();
	d.print();
	d.remove(6);
	d.print();
	int b;
	std::cin >> b;
}
