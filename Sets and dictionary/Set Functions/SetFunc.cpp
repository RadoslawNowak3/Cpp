#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <chrono>
#define N 1000000
using namespace std;
class simpleSet
{
public:
	int* data;
	int setSize = 0;
	simpleSet() {
		data = new int[N];
		for (int i = 0; i < N; i++)
			data[i] = 0;
	};
	~simpleSet()
	{
		delete[] data;
	}
	void sInsert(int x)
	{
		if (setSize >= N)
		{
			cout << "set is full" << endl;
			return;
		}

		if (data[x] != true)
		{
			data[x] = true;
			setSize++;
			return;
		}
		cout << "element already a part of the set" << endl;
	};
	void sWithdraw(int x)
	{
		if (data[x] == true)
		{
			data[x] = false;
			setSize--;
			return;
		}
		cout << "element not a part of the set" << endl;
	};
	bool sCheck(int x)
	{
		if (data[x] == 1)
			return true;
		return false;
	};
	int getSize()
	{
		return setSize;
	}
	void printSet()
	{
		int i;
		for (i = 0; i < N; i++)
			if (this->sCheck(i) == true)
			{
				cout << i << " ";
			}
		cout << endl;
	}
	static simpleSet setIntersection(simpleSet &A, simpleSet &B) {
		simpleSet result;
		int asize, bsize;
		if ((asize = A.getSize()) == 0 || (bsize = B.getSize()) == 0)
			return result;
		int acount = 0;
		int bcount = 0;
		for (int i = 0; i < N; i++)
		{
			if (A.sCheck(i) == true && B.sCheck(i) == true)
			{
				result.sInsert(i);
				acount++;
				bcount++;
			}
			if (acount == asize || bcount == bsize)
				break;
		}
		return result;
	};

	static simpleSet setUnion(simpleSet &A, simpleSet &B)
	{
		int asize, bsize;
		int acount = 0;
		int bcount = 0;
		int i = 0;
		simpleSet result;
		asize = A.getSize();
		bsize = B.getSize();
		if (asize != 0)
			for (int i = 0; i < N; i++)
			{
				if (A.sCheck(i) == true)
				{
					result.sInsert(i);
					acount++;
					if (acount == asize)
						break;
				}
			}
		if (bsize != 0)
			for (int i = 0; i < N; i++)
			{
				if (B.sCheck(i) == true)
				{
					bcount++;
					if (result.sCheck(i) == false)
						result.sInsert(i);
					if (bcount == bsize)
						break;
				}
			}
	}
	static simpleSet& setDifference(simpleSet &A, simpleSet &B)
	{
		if (A.getSize() == 0 || B.getSize() == 0)
			return A;
		simpleSet c = A;
		for (int i = 0; i < N; i++)
		{
			if (B.sCheck(i) == true)
				c.sWithdraw(i);
		}
		return c;
	}

	bool operator == (simpleSet &B)
	{
		int asize = this->getSize();
		int bsize = B.getSize();
		if (asize != bsize)
			return false;
		for (int i = 0; i < N; i++)
			if (this->sCheck(i) != B.sCheck(i))
				return false;
		return true;
	}
	bool operator > (simpleSet &B)
	{
		int asize = this->getSize();
		int bsize = B.getSize();
		if (asize > bsize)
			return true;
		return false;
	}
	bool operator < (simpleSet &B)
	{
		int asize = this->getSize();
		int bsize = B.getSize();
		if (asize < bsize)
			return true;
		return false;
	}
};
void f1Insert(simpleSet &set, int n, int m, int mode)
{
	if (mode == -1)
		for (int i = n; i <= m; i++)
		{
			set.sInsert(i - n);
		}
	else
	{
		if (mode <= m && mode >= n)
			set.sInsert(mode - n);
		else
			cout << "number out of range" << endl;
	}

}
int f1getNumber(simpleSet &set, int n, int pos)
{
	if (set.sCheck(pos) == 0)
	{
		cout << "number not found" << endl;
		return -1;
	}
	return pos + n;
}
void f2Insert(simpleSet &set, int n, int m, int mode)
{
	int temp;
	if (mode == -1)
	{
		for (int i = n; i <= m; i += 2)
		{
			temp = (i - n) / 2;
			set.sInsert(temp);
		}
	}
	else
	{
		if (mode <= m && mode >= n)
		{
			temp = (mode - n) / 2;
			set.sInsert(temp);
		}
		else
			cout << "number out of range" << endl;
	}
}
int f2getNumber(simpleSet &set, int n, int pos)
{
	if (set.sCheck(pos) == 0)
	{
		cout << "number not found" << endl;
		return -1;
	}
	return n + pos * 2;
}
void f3Insert(simpleSet &set, char a)
{
	int value = (int)a;
	if (value < 97 || value>122)
	{
		cout << "not a lowercase letter" << endl;
		return;
	}
	set.sInsert(value - 97);
}
char f3getNumber(simpleSet &set, int pos)
{
	if (set.sCheck(pos) == 0)
	{
		cout << "letter not found" << endl;
		return -1;
	}
	return (char)pos + 97;
}
void f4Insert(simpleSet &set, string a)
{
	if (a.length() != 2)
	{
		cout << "wrong string length" << endl;
		return;
	};
	if (a == "11")
	{

	}
	if (a[0] < 97 || a[0]>122)
	{
		cout << "one of the elements is not a lowercase letter" << endl;
		return;
	}
	if (a[1] < 97 || a[1]>122)
	{
		cout << "one of the elements is not a lowercase letter" << endl;
		return;
	}
	int first = (int)a[0] - 97;
	int second = (int)a[1] - 97;
	set.sInsert(first * 26 + second);
}
string f4getNumber(simpleSet &set, int pos)
{
	if (set.sCheck(pos) == 0)
	{
		cout << "string not found" << endl;
		return "NULL";
	}
	char first = pos / 26 + 97;
	char second = pos % 26 + 97;
	string result;
	result = first;
	result += second;
	return result;
}

int main()
{
	simpleSet set2;
	f2Insert(set2, 50, 250, -1);
	for (int i = 0; i < set2.setSize; i++)
		cout << f2getNumber(set2, 50, i) << endl;
	simpleSet set3;
	f3Insert(set3, 'a');
	f3Insert(set3, 'd');
	cout << f3getNumber(set3, 0) << endl;
	cout << f3getNumber(set3, 3) << endl;
	cout << f3getNumber(set3, 4) << endl;
	simpleSet set4;
	f4Insert(set4, "bb");
	f4Insert(set4, "aa");
	cout << f4getNumber(set4, 27) << endl;
	cout << f4getNumber(set4, 0) << endl;
	cout << f4getNumber(set4, 1) << endl;
	simpleSet set1;
	f1Insert(set1, 50, 250, 65);
	f1Insert(set1, 50, 250, 65);
	cout << f1getNumber(set1, 50, 15) << endl;
}