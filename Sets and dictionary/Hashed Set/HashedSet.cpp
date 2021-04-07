#include <iostream>
#include <time.h>
#include <chrono>
#include <fstream>
using namespace std;

struct Node {
	int value;
	Node * next = nullptr;
	void operator = (Node &A)
	{
		this->value = A.value;
		this->next = A.next;
	}
};

class HashedSet {

public:
	Node * table[10];
	int setSize;
	HashedSet() {
		for (int i = 0; i < 10; i++)
		{
			table[i] = nullptr;
		}
		setSize = 0;
	}
	int hash(int val)
	{
		return val % 10;
	}
	void insert(int val) {
		int index = val % 10;
		Node *newNode = new Node;
		newNode->value = val;
		if (table[index] == nullptr)
		{
			newNode->next = nullptr;
			table[index] = newNode;
			setSize++;
		}
		else
		{
			Node * curr = table[index];
			if (check(newNode->value) == true)
			{
				cout << "element already part of the set" << endl;
				return;
			}
			if (curr->value > val)
			{
				newNode->next = curr;
				table[index] = newNode;
				setSize++;
				return;
			}
			while (curr->next != nullptr)
			{
				if (curr->next->value > val)
				{
					newNode->next = curr->next;
					curr->next = newNode;
					setSize++;
				}
				curr = curr->next;

			}
			newNode->next = nullptr;
			curr->next = newNode;
			setSize++;
		}
	}
	void remove(int val) {

		if (setSize == 0) {
			cout << "Set is empty" << endl;
			return;
		}
		if (check(val) == false)
		{
			cout << "element not found" << endl;
			return;
		}
		int index = hash(val);
		Node* curr = table[index];
		if (curr->value == val)
		{
			if (curr->next == nullptr)
			{
				table[index] = nullptr;
			}
			else
				table[index] = curr->next;
			delete curr;
			setSize--;
		}
		else
		{
			while (curr->next->value != val)
				curr = curr->next;
			curr->next = curr->next->next;
			delete curr->next;
			setSize--;
		}
	}

	void printSet() {
		if (setSize == 0) {
			cout << "Empty Set" << endl;
			return;
		}
		else {
			Node* current;
			for (int i = 0; i < 10; i++)
			{
				if (table[i] != nullptr)
				{
					current = table[i];
					while (current != nullptr)
					{
						cout << current->value << " ";
						current = current->next;
					}
					cout << endl;
				}
			}
		}
		cout << endl;
	}

	bool check(int val)
	{
		if (setSize == 0) {
			return false;
		}
		int index = hash(val);
		Node* curr = table[index];
		while (curr != nullptr)
		{
			if (curr->value == val)
				return true;
			curr = curr->next;
		}
		return false;
	}

	static HashedSet setUnion(HashedSet &A, HashedSet &B)
	{
		HashedSet result;
		Node* curra;
		Node* currb;
		int i;
		for (i = 0; i < 10; i++)
		{
			curra = A.table[i];
			while (curra != nullptr)
			{
				result.insert(curra->value);
				curra = curra->next;
			}
		}
		for (i = 0; i < 10; i++)
		{
			currb = B.table[i];
			while (currb != nullptr)
			{
				result.insert(currb->value);
				currb = currb->next;
			}
		}
		return result;
	}

	static HashedSet setIntersection(HashedSet &A, HashedSet &B)
	{
		HashedSet result;
		Node* currA;
		Node* currB;
		int i;
		for (i = 0; i < 10; i++)
		{
			currA = A.table[i];
			while (currA != nullptr)
			{
				if (B.check(currA->value) == true)
				{
					result.insert(currA->value);
				}
				currA = currA->next;
			}
		}
		return result;
	}

	static HashedSet setDifference(HashedSet &A, HashedSet &B)
	{
		HashedSet result;
		Node* currA;
		int i;
		for (i = 0; i < 10; i++)
		{
			currA = A.table[i];
			while (currA != nullptr)
			{
				if (B.check(currA->value) == false)
				{
					result.insert(currA->value);
				}
				currA = currA->next;
			}
		}
		return result;
	}


};

bool areUnique(HashedSet &A, HashedSet &B)
{
	if (A.setSize != B.setSize)
		return false;
	HashedSet result;
	Node* currA;
	int i;
	for (i = 0; i < 10; i++)
	{
		currA = A.table[i];
		while (currA != nullptr)
		{
			if (B.check(currA->value) == false)
			{
				return false;
			}
			currA = currA->next;
		}
	}
	return true;
}
int main()
{
	HashedSet set;
	set.insert(45);
	set.insert(26);
	set.insert(16);
	set.insert(71);
	HashedSet set2;
	set2.insert(25);
	set2.insert(71);
	set2.insert(16);
	set2.insert(21);
	set2.remove(21);
	set2.remove(24);
	set2.insert(31);
	set2.insert(26);
	HashedSet set3 = HashedSet::setUnion(set, set2);
	HashedSet set4 = HashedSet::setIntersection(set, set2);
	HashedSet set5 = HashedSet::setDifference(set2, set);
	set.printSet();
	set2.printSet();
	set3.printSet();
	set4.printSet();
	set5.printSet();
	if (areUnique(set, set2) == true)
		cout << "Sets are identical" << endl;
	HashedSet set6;
	HashedSet set7;
	set6.insert(5);
	set6.insert(15);
	set6.insert(10);
	set7.insert(5);
	set7.insert(10);
	set7.insert(15);
	if (areUnique(set6, set7) == true)
		cout << "Sets are identical" << endl;
	/*
	srand(time(NULL));
	int i;
	ofstream dane("dane2.txt");
	double howlong;
	for (i = 0; i < 200; i++)
	{
		HashedSet setx;
		auto start1 = chrono::high_resolution_clock::now();
		for (int j = 0; j < 200 * i; j++)
		{
			setx.insert(j);
		}
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> time = end1 - start1;
		howlong = time.count();
		dane << 200 * i << " " << howlong << endl;
		cout << i << endl;

	}
	dane << "e" << endl;
	dane.close();
	*/
};