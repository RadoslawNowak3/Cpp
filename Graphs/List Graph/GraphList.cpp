#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <string>
#include <fstream>
#define SIZE 50000
using namespace std;
struct Vertex {
	int value;
	int id;
	Vertex* next;
	Vertex()
	{
		value = -1;
		id = -1;
		next = nullptr;
	}
	Vertex operator =(Vertex &other)
	{
		this->value = other.value;
		this->id = other.id;
		this->next = other.next;
	}
};

class GraphL
{
public:
	int vertices;
	Vertex* list[SIZE];

	GraphL()
	{
		vertices = 0;
		for (int i = 0; i < SIZE; i++)
		{
			list[i] = new Vertex;
		}
	}
	bool adjacent(int x, int y)
	{
		if (x < 0 || x > SIZE)
			return false;
		if (y < 0 || y > SIZE)
			return false;
		if (list[x]->next == nullptr)
			return false;
		Vertex* curr = new Vertex;
		curr = list[x];
		while (curr->next != nullptr&&curr->next->id != y)
		{
			curr = curr->next;
		}
		if (curr->next == nullptr)
			return false;

			return true;
	}
	void neighbours(int x)
	{
		if (x < 0 || x > vertices)
			return;
		if (list[x]->next == nullptr)
			return;
		Vertex* curr = new Vertex;
		curr = list[x];
		while (curr->next != nullptr)
		{
			cout << curr->next->id << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	void addVertex(int x)
	{
		if (x < 0 || vertices >= SIZE)
		{
			cout << "vertex outside of range / list is full " << endl;
			return;
		}
		if (list[x]->id != -1)
		{
			cout << "vertex already exists" << endl;
			return;
		}
		Vertex* node = new Vertex;
		node->id = x;
		list[x] = node;
		vertices++;
	}
	void removeVertex(int x)
	{
		if (x < 0 || vertices >= SIZE)
		{
			cout << "vertex outside of range / list is full " << endl;
			return;
		}
		if (list[x]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		Vertex* newNode;
		delete[] list[x]->next;
		list[x] = newNode;
		vertices--;
	}
	void addEdge(int x, int y)
	{
		if (x < 0 || x > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return;
		}
		if (y < 0 || y > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return;
		}
		if (list[x]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		if (list[y]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		Vertex* add1 = new Vertex;
		Vertex* add2 = new Vertex;
		Vertex* curr = new Vertex;
		add1->id = y;
		add2->id = x;
		add1->value = y % 3 + 1;
		add2->value = x % 3 + 1;
		curr = list[x];
		while (curr->next != nullptr&&curr->next->id<add1->id)
		{
			curr = curr->next;
		}
		if(curr->next==nullptr)
		curr->next = add1;
		else
		{
			if (curr->next->id == add1->id)
			{
				cout << "edge already exists" << endl;
				return;
			}
			add1->next = curr->next;
			curr->next = add1;
		}
		curr = list[y];
		while (curr->next != nullptr&&curr->next->id < add2->id)
		{
			curr = curr->next;
		}
		if (curr->next == nullptr)
			curr->next = add2;
		else
		{
			if (curr->next->id == add1->id)
			{
				cout << "edge already exists" << endl;
				return;
			}
			add2->next = curr->next;
			curr->next = add2;
		}
	}
	void removeEdge(int x, int y)
	{
		if (x < 0 || x > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return;
		}
		if (y < 0 || y > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return;
		}
		if (list[x]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		if (list[y]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		Vertex* curr;
		curr = list[x];
		while (curr->next != nullptr&&curr->next->id < y)
		{
			curr = curr->next;
		}
		if (curr->next->id == y)
		{
			curr->next = curr->next->next;
		}
		else
		{
			cout << "edge doesnt exist" << endl;
			return;
		}
		curr = list[y];
		while (curr->next->id != x)
		{
			curr = curr->next;
		}
		curr->next = curr->next->next;
	}
	void setVertexValue(int x,int val)
	{
		if (x < 0 || x > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return;
		}
		if (list[x]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		list[x]->value = val;
	}
	void setEdgeValue(int x, int y, int val)
	{
		if (x < 0 || x > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return;
		}
		if (list[x]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		if (y < 0 || y > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return;
		}
		if (list[y]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}

		Vertex* curr;
		curr = list[x];
		while (curr->next != nullptr&&curr->next->id != y)
		{
			curr = curr->next;
		}
		if (curr->next == nullptr)
		{
			cout << "edge doesnt exist" << endl;
			return;
		}
		curr->next->value = val;
		curr = list[y];
		while (curr->next->id != x)
		{
			curr = curr->next;
		}
		curr->next->value = val;
	}

	int getEdgeValue(int x, int y)
	{
		
		if (x < 0 || x > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return -1;
		}
		if (list[x]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return -1;
		}
		Vertex* curr = new Vertex;
		curr = list[x];
		while (curr->next != nullptr&&curr->next->id != y)
		{
			curr = curr->next;
		}
		if (curr->next == nullptr)
		{
			cout << "edge doesnt exist" << endl;
			return -1;
		}
		return curr->next->value;
	}
	int getVertexValue(int x)
	{
		if (x < 0 || x > SIZE)
		{
			cout << "vertex outside of range" << endl;
			return -1;
		}
		if (list[x]->id == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return -1;
		}
		Vertex* curr = new Vertex;
		curr = list[x];
		return curr->value;
	}

	void printGraph()
	{
		int i;
		Vertex*curr = new Vertex;
		for (i = 0; i < SIZE; i++)
		{
			if (list[i]->id != -1)
			{
				curr = list[i];
				cout << i << " ";
				while (curr->next != nullptr)
				{
					curr = curr->next;
					cout << curr->id << " ";
				}
				cout << endl;
			}
		}
	}
};


int main()
{
	GraphL set;
	set.addVertex(1);
	set.addVertex(3);
	set.addVertex(4);
	set.addVertex(5);
	set.addVertex(6);
	set.addEdge(3, 1);
	set.addEdge(6, 6);
	set.addEdge(1, 3);
	if (set.adjacent(1, 3) == true)
		cout << "true" << endl;
	 set.setEdgeValue(3,1,4);
	 cout << set.getEdgeValue(1, 3) << endl;
	 set.addEdge(4, 4);
	 set.addEdge(4, 8);
	set.addEdge(3, 6);
	set.printGraph();
	set.neighbours(3);
	cout << set.getVertexValue(1) << endl;
	set.setVertexValue(1,5);
	cout << set.getVertexValue(1);

	/*
	ofstream dane("dane.txt");
double howlong;
int i, j;
for (i = 1; i < 500; i++)
{
	GraphL set;
	auto start1 = chrono::high_resolution_clock::now();
	for (j = 0; j < 50 * i; j++)
	{
		set.addVertex(j);
	}
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> time = end1 - start1;
	howlong = time.count();
	dane << 50 * i << " " << howlong << endl;
	cout << i << endl;
}
dane << "e" << endl;

dane.close();
	*/
}
