#ifndef UNTITLED_SortedLinkedList_H
#define UNTITLED_SortedLinkedList_H
#include <iterator>
#include <iostream>
#include <algorithm>
#include <memory>
#define MAXSIZE 100000
template<class T>
class SortedLinkedList {

public:
	struct Node {
		T x;
		Node* prev = nullptr;
		Node* next = nullptr;
		Node() {};
		Node(T value, Node* prev = nullptr, Node* next = nullptr)
		{
			x = value;
		}
	};
	struct iterator {
		Node* ptr;
		iterator(Node *newPtr) : ptr(newPtr) {}
		iterator() : iterator(nullptr) {}
		iterator &operator++()
		{
			this->ptr = this->ptr->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator itr(*this);
			this->ptr = this->ptr->next;
			return itr;
		}
		iterator &operator--()
		{
			this->ptr = this->ptr->prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator itr(*this);
			this->ptr = this->ptr->prev;
			return itr;
		}
		T &operator*()
		{
			return this->ptr->x;
		}
		bool operator==(const iterator &i) const
		{
			return this->ptr == i.ptr;
		}
		bool operator!=(const iterator &i) const
		{
			return !operator==(i);
		}
		T* operator->()
		{
			return &(this->ptr->x);
		}

	};

	using pointer = Node * ;
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
	SortedLinkedList<T>() {
	}
	SortedLinkedList<T>(const SortedLinkedList &list)
	{
		if (list.head == nullptr)
		{
			size = 0;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = new Node(list.head->x);
			Node* tail = new Node;
			Node* current = head;
			Node* listHead = list.head;
			Node* listCurrent = listHead;
			while (listCurrent->next != nullptr)
			{
				current->next = new Node(listCurrent->next->x);
				current->next->prev = current;
				tail = current;
				current = current->next;
				size++;
				listCurrent = listCurrent->next;
			}
		}

	}
	~SortedLinkedList<T>()
	{
		Node *current = head;
		while (current != nullptr)
		{
			Node* toDelete = current;
			current = current->next;
			if (current != nullptr)
				current->prev = nullptr;
			delete toDelete;
			size--;
		}
	}
	/*SortedLinkedList<T>& SortedLinkedList::operator=(const SortedLinkedList& rhs)
	{
		std::swap(head, rhs.head);
		std::swap(tail, rhs.tail);
		return *this;
	}
	*/
	iterator begin() {
		return iterator(head);
	}

	iterator end() {
		return iterator(tail);
	}
	void push(T x) {// Wstawia element 'x'
		if (size == MAXSIZE) {
			std::cout << "Lista jest pelna" << std::endl;
			return;
		}
		Node* newNode = new Node;
		newNode->x = x;
		if (size == 0) {
			head = newNode;
			tail = head;
		}
		else if (head->x >= newNode->x) {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		else {
			Node *tmp = head;
			while (tmp->next != nullptr && tmp->next->x < newNode->x) {
				tmp = tmp->next;
			}
			newNode->next = tmp->next;
			tmp->next = newNode;
			newNode->prev = tmp;
			if (newNode->next != nullptr)
			{
				newNode->next->prev = newNode;
			}
			else
				tail = newNode;
		}
		size++;
	}

	T pop() {  // Zwraca i usuwa pierwszy (najmniejszy) element
		if (size == 0) {
			std::cout << "Lista jest pusta" << std::endl;
			return -1;
		}
		T temp;
		temp = head->x;
		if (head->next != nullptr) {
			head = head->next;
			delete(head->prev);
		}
		else {
			head->next = nullptr;
			head->prev = nullptr;
			head = nullptr;
			tail = head;
		}
		size--;
		return temp;
	}
	T erase(iterator i) { // Usuwa element na pozycji 'i' i zwraca jego wartość
		if (i.ptr == nullptr)
		{
			std::cout << "Iterator wskazuje na null!" << std::endl;
		}
		T value = *i;
		if (i.ptr == head) {
			head = i.ptr->next;
		}
		if (i.ptr == tail) {
			tail = i.ptr->prev;
		}
		if (i.ptr->prev != nullptr) {
			i.ptr->prev->next = i.ptr->next;
		}
		if (i.ptr->next != nullptr) {
			i.ptr->next->prev = i.ptr->prev;
		}
		delete i.ptr;
		--size;
		return value;


	}
	iterator find(T x) {  // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
		if (size != 0 && (x<head->x || x>tail->x)) {
			return end();
		}
		for (auto i = begin(); i != end(); ++i) {
			if (i.ptr->x == x) {
				return iterator(i.ptr);
			}
		}
		return end();
	}
	int listSize() // Zwraca rozmiar listy
	{
		return size;
	}
	void remove(T value) { // Usuwa wszystkie elementy równe 'value'

		if (size == 0) {
			std::cout << "Lista jest pusta" << std::endl;
			return;
		}
		Node* tmp = head;
		while (tmp != nullptr)
		{
			if (tmp->x == value)
			{
				if (tmp == tail)
					tail = tmp->prev;
				Node* toRemove = tmp;
				tmp->prev->next = tmp->next;
				if (tmp->next != nullptr)
					tmp->next->prev = tmp->prev;
				tmp = tmp->next;
				delete(toRemove);
				size--;
			}
			else
				tmp = tmp->next;
		}
	};

	static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b) { // Scala dwie posortowane listy i zwraca posortowaną listę
		SortedLinkedList<T> mergedList;
		mergedList.size = a.size + b.size;
		Node *node1 = a.head;
		Node *node2 = b.head;
		while (node1 || node2) {
			T value;
			if (node1 && (node2 == nullptr || node1->x < node2->x)) {
				value = node1->x;
				node1 = node1->next;
			}
			else {
				value = node2->x;
				node2 = node2->next;
			}
			Node *n = new Node;
			n->x = value;
			if (mergedList.head == nullptr) {
				mergedList.head = n;
			}
			else {
				mergedList.tail->next = n;
				n->prev = mergedList.tail;
			}
			mergedList.tail = n;
		}
		return mergedList;
	}
	void unique() {  // Usuwa sąsiadujące duplikaty
		if (size < 2) {
			std::cout << "Lista jest zbyt mala na wystapienie duplikatow" << std::endl;
			return;
		}
		else {
			Node *tmp = head;
			while (tmp->x == tmp->next->x&&tmp->next != nullptr)
			{
				Node* toRemove = tmp;
				tmp->next->prev = nullptr;
				tmp->next = head;
				tmp = tmp->next;
				delete(toRemove);
				size--;
			}
			while (tmp != nullptr&& tmp->next != nullptr)
			{
				if (tmp->x == tmp->next->x)
				{
					Node* toRemove = tmp;
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					tmp = tmp->next;
					if (tmp->next == nullptr)
						tmp = tail;
					delete(toRemove);
					size--;
				}
				else
					tmp = tmp->next;
			}
		}
	}
	template <class U>
	void Push(U&& obj) {// Wstawia obiekt obj
		if (size == MAXSIZE) {
			std::cout << "Lista jest pelna" << std::endl;
			return;
		}
		Node* newNode = new Node(std::forward<U>(obj));
		if (size == 0) {
			head = newNode;
			tail = head;
		}
		else if (head->x >= newNode->x) {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		else {
			Node *tmp = head;
			while (tmp->next != nullptr && tmp->next->x < newNode->x) {
				tmp = tmp->next;
			}
			newNode->next = tmp->next;
			tmp->next = newNode;
			newNode->prev = tmp;
			if (newNode->next != nullptr)
			{
				newNode->next->prev = newNode;
			}
			else
				tail = newNode;
		}
		size++;
	}
	void print() { // Wypisuje elementy listy
		if (size == 0) {
			std::cout << "Lista jest pusta";
			return;
		}
		else {
			Node * tmp = head;
			while (tmp != nullptr) {
				std::cout << tmp->x << " ";
				tmp = tmp->next;
			}
		}
		std::cout << std::endl;
	}
};

#endif
