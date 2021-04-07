#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <fstream>
#define N 2000000
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
	void sInsert(int x)
	{
		if (data[x] != true)
		{
			data[x] = true;
			setSize++;
		}
	};
	void sWithdraw(int x)
	{
		if (data[x] == true)
		{
			data[x] = false;
			setSize--;
		}
	};
	bool sCheck(int x)
	{
		if (data[x] == true)
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
		return result;
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

	/* bool operator == (simpleSet &B)
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
		 if(asize < bsize)
		 return false;
		 int sum1=0;
		 int sum2=0;
		 for(int i=0;i<asize;i++)
		 {

		 }


	 }
	 bool operator < (simpleSet &B)
	 {
		 int asize = this->getSize();
		 int bsize = B.getSize();
		 if (asize < bsize)
			 return true;
		 return false;
	 }
	 */
};

int main()
{
	srand(time(NULL));
	int i;
	simpleSet setx;
	/*	setx.sInsert(2);
		setx.sInsert(3);
		setx.sInsert(4);
		setx.printSet();
		for(int i=0;i<5;i++)
		cout << setx.data[i] << endl;
		simpleSet sety;
		sety.sInsert(7);
		sety.sInsert(5);
		sety.sInsert(3);
		cout << endl;
		simpleSet setz;
		setz = simpleSet::setIntersection(setx, sety);
		setz.printSet();
		simpleSet seta;
		simpleSet setb;
		seta = simpleSet::setUnion(setx, sety);
		setb = simpleSet::setDifference(setx, sety);
		seta.printSet();
		setb.printSet();
		*/
	ofstream dane("dane2.txt");
	double howlong;
	for (i = 0; i < 250; i++)
	{
		auto start1 = chrono::high_resolution_clock::now();
		for (int j = 0; j < 2000 * i; j++)
		{
			setx.sInsert(j);
		}
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<double> time = end1 - start1;
		howlong = time.count();
		dane << 2000 * i << " " << howlong << endl;
		cout << i << endl;

	}
	dane << "e" << endl;
	dane.close();

	return 0;
}

