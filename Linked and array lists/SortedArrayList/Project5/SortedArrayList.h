#pragma once
#ifndef SORTEDARRAYLIST_H
#define SORTEDARRAYLIST_H
#include <iostream>
#include <algorithm>
#define SIZE 100000
template<class T>
class SortedArrayList
{
public:
	struct iterator {
		T * ptr;
		iterator(T *pos) : ptr(pos) {};
		iterator() : ptr(nullptr) {};
		iterator& operator++() {
			this->ptr++;
			return *this;
		}
		iterator operator++(int) {
			auto oldValue = *this;
			operator++();
			return oldValue;
		}
		iterator operator--(int) {
			auto oldValue = *this;
			operator--();
			return oldValue;
		}
		iterator& operator--() {
			this->ptr--;
			return *this;
		}
		T& operator*() {
			return *ptr;
		}
		bool operator==(iterator iterator1) {
			return this->ptr == iterator1.ptr;
		}
		bool operator!=(iterator iterator1) {
			return !operator==(iterator1);
		}
		bool operator<(const iterator &iterator1) const
		{
			return this->ptr < iterator1.ptr;
		}
		bool operator>(const iterator &iterator1) const
		{
			return this->ptr > iterator1.ptr;
		}
		bool operator>=(const iterator &iterator1) const
		{
			return this->ptr >= iterator1.ptr;
		}
		bool operator<=(const iterator &iterator1) const
		{
			return this->ptr <= iterator1.ptr;
		}
		iterator operator-(int pos)
		{
			return iterator(ptr - pos);
		}
		iterator operator+(int pos)
		{
			return iterator(ptr + pos);
		}

	};
	T* array;
	int elementsCount;
	SortedArrayList<T>() // konstruktor
	{
		array = new T[SIZE];
		elementsCount = 0;
	}
	SortedArrayList<T>(const SortedArrayList &list) // konstruktor kopiujacy
	{
		elementsCount = list.elementsCount;
		array = new T[elementsCount];
		std::copy(list.array,list.array + elementsCount, array);
	}
	/*SortedArrayList<T>(SortedArrayList &&list) // konstruktor przenoszacy
	{
		array = std::move(list.array);
	}
	*/
	SortedArrayList<T>& operator=(const SortedArrayList& list)
	{
		if (this != &list)
		{
			delete[] array;
			elementsCount = list.elementsCount;
			array = new T[elementsCount];
			std::copy(list.array, list.array+elementsCount, array);
		}
		return *this;
	}
	~SortedArrayList<T>()
	{
		delete[] array;
	}
	iterator begin() {
		return iterator{array};
	}
	iterator end() {
		return iterator{array + elementsCount};
	}
	iterator insert(iterator i2, const T& b) { // Wstawia element 'b' na pozycji i2
		for (int j = this->elementsCount; j > i2.ptr; j--) {
			this->array[j] = this->array[j - 1];
		}
		this->array[i2.ptr] = b;
		this->elementsCount++;
	}
	T erase(iterator it) {
		if (it < begin() || it > end())
		{
			std::cout << "Brak takiego indeksu w liscie" << std::endl;
			return -1;
		}
		else {
		T value = *it;
		iterator before_end = end()--;
		while (it != before_end) {
			auto prev = it++;
			*prev = *it;
		}
		elementsCount--;
		return value;
		}
	}
	void push(T x) { // Wstawia element 'x' na poczatek listy
		if (elementsCount >= SIZE) {
			std::cout << "Lista jest pelna!" << std::endl;
		}
		else if (elementsCount == 0) {
			array[0] = x;
			elementsCount++;
		}
		else {
			for (int i = 0; i < elementsCount; i++) {
				if (array[i] >= x) {
					for (int j = elementsCount; j > i; j--) {
						array[j] = array[j - 1];
					}
					array[i] = x;
					elementsCount++;
					return;
				}
				if (i == elementsCount - 1) {
					array[i + 1] = x;
					elementsCount++;
					return;
				}
			}
		}
	}

	T pop() { // Zwraca i usuwa pierwszy (najmniejszy) element
		if (elementsCount == 0) {
			std::cout << "Lista jest pusta" << std::endl;
			return -1;
		}
		T tmp;
		tmp = array[0];
		for (int i = 0; i < elementsCount; i++) {
			array[i] = array[i + 1];
		}
		elementsCount--;
		return tmp;
	}

	iterator find(T x) { // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
			auto found = std::lower_bound(array, array + elementsCount, x);
			if (found == array + elementsCount|| *found != x)
				return end();
			return iterator{ found };
		}
	int size() { // Zwraca rozmiar tablicy
		return elementsCount;
	}
	void remove(T x) { // Usuwa element o wartosci 'x' z listy
		if (elementsCount == 0) {
			std::cout << "Lista jest pusta" << std::endl;
			return;
		}
		for (int i = 0; i < elementsCount; i++) {
			if (array[i] == x) {
				for (int j = i; j < elementsCount - 1; j++) {
					array[j] = array[j + 1];
				}
				elementsCount--;
				i--;
			}
		}
	}

	static SortedArrayList merge(const SortedArrayList& array1, const SortedArrayList& array2) { // Scala dwie posortowane lsity w jedna
		SortedArrayList<T> mergedList;
		mergedList.elementsCount = array1.elementsCount + array2.elementsCount;
		int i = 0, j = 0, k = 0;
		while (i < array1.elementsCount && j < array2.elementsCount) {
			if (array1.array[i] < array2.array[j]) {
				mergedList.array[k] = array1.array[i];
				k++;
				i++;
			}
			else {
				mergedList.array[k] = array2.array[j];
				k++;
				j++;
			}
		}
		while (i < array1.elementsCount) {
			mergedList.array[k] = array1.array[i];
			k++;
			i++;
		}
		while (j < array2.elementsCount) {
			mergedList.array[k] = array2.array[j];
			k++;
			j++;
		}
		return mergedList;
	}

	void unique() { // usuwa duplikaty
		for (int i = 0; i < elementsCount - 1; i++) {
			if (array[i] == array[i + 1]) {
				for (int j = i; j < elementsCount - 1; j++) {
					array[j] = array[j + 1];
					i--;
					elementsCount--;
				}
				
			}
		}
	}
	
	void print() { // wypisuje zawartosc listy
		for (const auto& a : *this) {
			std::cout << a << " ";
		}
		std::cout << std::endl;
		}

	template <class U>
	void Push(U&& obj) {
		if (elementsCount >= SIZE) {
			std::cout << "Lista jest pelna " << std::endl;
			return;
		}
		int i;
		for (i = elementsCount - 1; i >= 0 && array[i] >= obj; i--)
		{
			array[i + 1] = array[i];
		}
		array[i + 1] = std::forward<U>(obj);
		elementsCount++;
	}
};

#endif
