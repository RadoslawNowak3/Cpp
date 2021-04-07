#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;
class PriorityQueue {
public:
	struct Pqitem
	{
		int priority;
		int value;
		Pqitem *next;
		Pqitem()
		{
			priority = 0;
			value = 0;
			next = nullptr;
		}
	};
	Pqitem* head;
	Pqitem* tail;
	int size = 0;
	void enqueue(int data)
	{
		Pqitem* node = new Pqitem;
		node->priority = data;
		node->value = data;
		if (head == nullptr)
		{
			node->next = nullptr;
			head = node;
			tail = node;
			size++;
			return;
		}
		if (head->priority < node->priority)
		{
			node->next = head;
			head = node;
			size++;
			return;
		}
		Pqitem* temp;
		temp = head;
		while (temp->next != nullptr && temp->next->priority >= node->priority)
		{
			temp = temp->next;
		}
		if (temp->priority == node->priority)
		{
			cout << "item already in queue" << endl;
			return;
		}
		node->next = temp->next;
		temp->next = node;
		size++;
		if (node->next == nullptr)
			tail = node;
	}

	Pqitem* dequeue()
	{
		Pqitem* node = new Pqitem;
		if (head == nullptr)
		{
			cout << "queue is empty" << endl;
			return node;
		}
		node = head;
		head->next = head;	
		if (head == nullptr)
			tail = nullptr;
		return node;
	}

	int p(int value)
	{
		if (head == nullptr)
		{
			cout << "queue is empty" << endl;
			return -1;
		}
		Pqitem* curr = head;
		while (curr->next != nullptr&&curr->value != value)
		{
			curr = curr->next;
		}
		if (curr->value != value)
		{
			cout << "element not found" << endl;
			return -1;
		}
		return curr->priority;

	}

	void printQueue()
	{
		if (head == nullptr)
		{
			cout << "queue is empty" << endl;
			return;
		}
		Pqitem* curr;
		curr = head;
		while (curr != nullptr)
		{
			cout << curr->value << " ";
			curr = curr->next;
		}
		cout << endl;
	}

};

int main()
{
	

	//ofstream dane("dane.txt");
	// double howlong;
	int i, j;
	/*for (i = 1; i < 300; i++)
	{
		PriorityQueue queue;
		auto start1 = chrono::high_resolution_clock::now();
		for (j=0; j < 500*i; j++)
		{
			queue.enqueue(j);
		}
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> time = end1 - start1;
		howlong = time.count();
		dane << 500 * i << " " << howlong << endl;
		cout << i << endl;
	}
	dane << "e" << endl;
	*/
	PriorityQueue queue;
	queue.enqueue(5);
	queue.enqueue(6);
	queue.enqueue(3);
	cout << queue.p(5);
	// dane.close();
}

