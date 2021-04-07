#include <iostream>
#include <time.h>
#include <chrono>
#include <fstream>
using namespace std;
class LinkedSet {

public:
	struct Node {
		int value;
		Node * next = nullptr;
		void operator = (Node &A)
		{
			this->value = A.value;
			this->next = A.next;
		}
	};
	Node * head;
	Node * tail;
	int setSize;
	LinkedSet() {
		head = nullptr;
		tail = nullptr;
		setSize = 0;
	}
	void insert(int val) {
		Node *newNode = new Node;
		newNode->value = val;
		if (setSize == 0)
		{
			newNode->next = nullptr;
			head = newNode;
			setSize++;
			return;
		}
		if (head->value > val)
		{
			newNode->next = head;
			head = newNode;
			setSize++;
			return;
		}
		Node * currentNode = head;
		while (currentNode != nullptr) {
			if (newNode->value == currentNode->value) {
				cout << "This number is already a part of the set." << endl;
				return;
			}
			if (currentNode->next != nullptr)
			{
				if ((currentNode->next->value) > val)
				{
					newNode->next = currentNode->next;
					currentNode->next = newNode;
					setSize++;
					return;
				}
				currentNode = currentNode->next;
			}
			else
			{
				newNode->next = nullptr;
				setSize++;
				currentNode->next = newNode;
				tail = newNode;
				return;
			}
		}
	}
	void remove(int val) {
		if (setSize == 0) {
			cout << "Set is empty" << endl;
			return;
		}

		if (head->value == val) {
			Node * temp = head->next;
			delete(head);
			setSize--;
			head = temp;
		}
		else {
			Node *tmp = head;
			while (tmp->next != nullptr && tmp->next->value < val)
			{
				tmp = tmp->next;
			}
			if (tmp->next == nullptr || tmp->next->value != val)
			{
				cout << "value not found" << endl;
				return;
			}
			Node * toRemove = tmp->next;
			tmp->next = tmp->next->next;
			delete(toRemove);
			setSize--;
		}
	}

	void printSet() {
		if (setSize == 0) {
			cout << "Empty Set" << endl;
			return;
		}
		else {
			Node * tmp = head;
			while (tmp != nullptr) {
				cout << tmp->value << " ";
				tmp = tmp->next;
			}
		}
		cout << endl;
	}
	bool check(int val)
	{
		if (setSize == 0) {
			return false;
		}
		Node* curr = head;
		while (curr != nullptr)
		{
			if (curr->value == val)
				return true;
			curr = curr->next;
		}
		return false;
	}
	static LinkedSet setMerge(LinkedSet &A, LinkedSet &B)
	{
		LinkedSet result;
		Node* currA = A.head;
		Node* currB = B.head;
		Node* curr = result.head;
		while (currA != nullptr && currB != nullptr)
		{
			if (currA->value > currB->value)
			{
				if (curr != currB)
				{
					result.insert(currB->value);
					curr = currB;
					currB = currB->next;
				}
				else
					currB = currB->next;
			}
			else
			{
				if (curr != currB)
				{
					result.insert(currA->value);
					curr = currA;
					currA = currA->next;
				}
				else
					currA = currA->next;
			}
		}
		while (currA != nullptr)
		{
			if (currA != curr)
			{
				result.insert(currA->value);
				curr = currA;
			}
			currA = currA->next;
		}
		while (currB != nullptr)
		{
			if (currB != curr)
			{
				result.insert(currB->value);
				curr = currB;
			}
			currB = currB->next;
		}
		return result;
	}
	static LinkedSet setUnion(LinkedSet &A, LinkedSet &B)
	{
		LinkedSet result;
		Node* currA = A.head;
		Node* currB = B.head;
		while (currA != nullptr)
		{
			while (currA->value >= currB->value && currB != nullptr)
			{
				if (currA->value == currB->value)
				{
					result.insert(currA->value);
					break;
				}
				currB = currB->next;
			}
			currA = currA->next;
		}
		return result;
	}
	static LinkedSet setDifference(LinkedSet &A, LinkedSet &B)
	{
		LinkedSet result = A;
		Node* curr = result.head;
		Node* currB = B.head;
		while (currB != nullptr)
		{
			if (result.check(currB->value) == true)
			{
				result.remove(currB->value);
			}
			currB = currB->next;
		}
		return result;
	}
	void operator = (LinkedSet &A)
	{
		Node* curr = A.head;
		while (curr != nullptr)
		{
			this->insert(curr->value);
			curr = curr->next;
		}

	}
	bool operator == (LinkedSet &A)
	{
		if (this->setSize != A.setSize)
			return false;
		Node* curr = this->head;
		Node* currA = A.head;
		while (curr->next != nullptr&&currA->next != nullptr)
		{
			if (curr->value != currA->value)
				return false;
			curr = curr->next;
			currA = currA->next;
		}
		return true;
	}
};

int main()
{
	LinkedSet set;
	set.insert(5);
	set.insert(6);
	set.insert(1);
	LinkedSet set2;
	set2.insert(8);
	set2.insert(1);
	set2.insert(6);
	set2.insert(1);
	LinkedSet set3 = LinkedSet::setMerge(set, set2);
	set3.printSet();
	LinkedSet set4 = LinkedSet::setUnion(set, set2);
	set4.printSet();
	LinkedSet set5 = LinkedSet::setDifference(set, set2);
	set5.printSet();
	set2.printSet();
	set2.remove(1);
	set2.remove(9);
	set2.printSet();

	/*
		srand(time(NULL));
		int i;
		ofstream dane("dane2.txt");
		double howlong;
		for (i = 0; i < 30; i++)
		{
			LinkedSet setx;
			auto start1 = chrono::high_resolution_clock::now();
			for (int j = 0; j < 2000 * i; j++)
			{
				setx.insert(j);
			}
			auto end1 = chrono::high_resolution_clock::now();
			chrono::duration<double> time = end1 - start1;
			howlong = time.count();
			dane << 2000 * i << " " << howlong << endl;
			cout << i << endl;

		}
		dane << "e" << endl;
		dane.close();
		*/
	return 0;
}
