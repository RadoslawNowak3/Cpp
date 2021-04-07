#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <string>
#include <fstream>

#define MAX 15000

using namespace std;

int compare(string a, string b)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < b[i])
		{
			return 1;
		}
		if (a[i] > b[i])
		{
			return 2;
		}
	}
	return 0;
}

class simpleDictionary
{
public:
	string* data;
	int setSize = 0;
	simpleDictionary() {
		data = new string[MAX];
	};
	void sInsert(string x)
	{
		if (x.length() != 50)
		{
			cout << "wrong size" << endl;
			return;
		}
		if (setSize >= MAX)
		{
			cout << "element limit reached" << endl;
			return;
		}
		if (setSize == 0)
		{
			data[0] = x;
			setSize++;
			return;
		}
		if (sCheck(x) == 1)
		{
			cout << "element already in set" << endl;
			return;
		}
		else
		{
			int i;
			for (i = 0; i < setSize; i++)
			{
				if (compare(x, data[i]) == 1)
				{
					for (int j = setSize; j >= i; j--)
					{
						data[j + 1] = data[j];
					}
					data[i] = x;
					setSize++;
					return;
				}
			}
			data[i] = x;
			setSize++;
			return;
		}
	};
	void sRemove(string x)
	{
		if (setSize == 0)
		{
			cout << "no elements to remove" << endl;
			return;
		}
		if (sCheck(x) == false)
		{
			cout << "element not a part of the set" << endl;
			return;
		}
		int i;
		for (i = 0; i < setSize; i++)
		{
			if (data[i] == x)
			{
				for (int j = i; j < setSize; j++)
				{
					data[j] = data[j + 1];
				}
				setSize--;
			}
		}
	}
	bool sCheck(string x)
	{
		for (int i = 0; i < setSize; i++)
			if (data[i] == x)
				return true;
		return false;
	};

	void printSet() {
		for (int i = 0; i < setSize; i++)
		{
			cout << data[i];
			cout << endl;
		}
	}

};
int main()
{
	srand(time(NULL));
	char tab[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	int size = 52;
	string text[MAX];
	string text1;
	int i;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 50; j++)
			text1 += tab[rand() % size];
		text[i] = text1;
		text1 = "";

	}
	cout << "koniec generowania tekstu" << endl;
	ofstream dane("dane2.txt");
	double howlong;
	for (i = 0; i < 50; i++)
	{
		simpleDictionary setx;
		auto start1 = chrono::high_resolution_clock::now();
		for (int j = 0; j < 50 * i; j++)
		{
			setx.sInsert(text[j]);
		}
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> time = end1 - start1;
		howlong = time.count();
		dane << 50 * i << " " << howlong << endl;
		cout << i << endl;

	}
	dane << "e" << endl;
	dane.close();
	/*
	simpleDictionary set1;
	set1.sInsert("abtesttesttesttesttesttesttesttesttesttesttesttest");
	set1.sInsert("cbtesttesttesttesttesttesttesttesttesttesttesttest");
	set1.sInsert("dctesttesttesttesttesttesttesttesttesttesttesttest");
	set1.sInsert("zstesttesttesttesttesttesttesttesttesttesttesttest");
	set1.sInsert("actesttesttesttesttesttesttesttesttesttesttesttest");
	set1.sInsert("ratesttesttesttesttesttesttesttesttesttesttesttest");
	set1.printSet();
	cout << endl;
	set1.sRemove("actesttesttesttesttesttesttesttesttesttesttesttest");
	set1.sRemove("bbtesttesttesttesttesttesttesttesttesttesttesttest");
	set1.printSet();
	*/
	return 0;
}