#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class GraphP {
public:
	struct Vertex {
		int value;
		int edgeval;
		bool mst;
		Vertex& operator =(Vertex&other)
		{
			edgeval = other.edgeval;
			value = other.value;
			return *this;

		}
	};
	Vertex **matrix;
	int vertexcount;
	GraphP()
	{
		vertexcount = 0;
	}
	GraphP(int size)
	{
		vertexcount = size;
		int i, j;
		matrix = new Vertex*[size];
		for (int i = 0; i < size; i++)
			matrix[i] = new Vertex[size];
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++) {
				matrix[i][j].value = 0;
				matrix[i][j].edgeval = 0;
			}
		}
	}

	bool adjacent(int x, int y)
	{
		int i;
		int val1 = -1;
		int val2 = -1;
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == x)
			{
				val1 = i;
				break;
			}
		}
		if (val1 == -1)
			return false;
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == y)
			{
				val2 = i;
				break;
			}
		}
		if (val2 == -1)
			return false;

		if (matrix[val1][val2].edgeval > 0 || matrix[val2][val1].edgeval > 0)
			return true;
		return false;
	}
	void neighbours(int x)
	{
		int val1 = -1;
		int i;
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == x)
			{
				val1 = i;
				break;
			}
		}
		if (val1 == -1)
		{
			cout << "value not found" << endl;
			return;
		}
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[val1][i].edgeval > 0)
				cout << i << " ";
			if (matrix[i][val1].edgeval > 0)
				cout << i << " ";
		}
		cout << endl;
	}

	void addVertex(int val)
	{
		if (vertexcount == 0)
		{
			vertexcount++;
			matrix = new Vertex*[0];
			matrix[0] = new Vertex[0];
			matrix[0][0].value = val;
			matrix[0][0].edgeval = 0;
			return;
		}
		for (int i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == val)
			{
				cout << "vertex already exists" << endl;
				return;
			}
		}
		int i, j;
		Vertex** temp;
		temp = new Vertex*[vertexcount];
		for (int i = 0; i < vertexcount; i++)
			temp[i] = new Vertex[vertexcount];

		for (i = 0; i < vertexcount; i++)
		{
			for (j = 0; j < vertexcount; j++)
				temp[i][j] = matrix[i][j];
		}

		vertexcount++;

		matrix = new Vertex*[vertexcount];
		for (int i = 0; i <= vertexcount; i++)
			matrix[i] = new Vertex[vertexcount];

		for (i = 0; i < vertexcount - 1; i++)
		{
			for (j = 0; j < vertexcount - 1; j++)
				matrix[i][j] = temp[i][j];
			matrix[i][j].value = 0;
			matrix[i][j].edgeval = 0;
		}
		for (j = 0; j < vertexcount; j++)
		{
			matrix[i][j].value = 0;
			matrix[i][j].edgeval = 0;
		}
		matrix[i][j - 1].value = val;
		delete[]temp;

	}
	void removeVertex(int val)
	{
		int i, j;
		int x = 100;
		int a = 0;
		int b = 0;
		Vertex** temp;
		temp = new Vertex*[vertexcount - 1];
		for (int i = 0; i < vertexcount - 1; i++)
			temp[i] = new Vertex[vertexcount - 1];
		for (i = 0; i < vertexcount; i++)
			if (matrix[i][i].value == val)
				x = val;
		for (i = 0; i < vertexcount - 1; i++)
		{
			b = 0;
			if (i == x)
			{
				a = 1;
				continue;
			}
			for (j = 0; j < vertexcount - 1; j++)
			{
				if (j == x)
				{
					b = 1;
					continue;
				}
				temp[i - a][j - b] = matrix[i][j];
			}
		}
		vertexcount--;
		matrix = new Vertex*[vertexcount];
		for (int i = 0; i < vertexcount; i++)
			matrix[i] = new Vertex[vertexcount];
		for (i = 0; i < vertexcount; i++)
		{
			for (j = 0; j < vertexcount; j++)
				matrix[i][j] = temp[i][j];
		}

		delete[]temp;
	}

	int getVertexValue(int x)
	{
		if (x > vertexcount)
		{
			cout << "outside of matrix range" << endl;
			return -1;
		}
		if (x < 0)
		{
			cout << "outside of matrix range" << endl;
			return -1;
		}
		return matrix[x][x].value;
	}
	void setVertexValue(int val, int x)
	{
		if (x > vertexcount)
		{
			cout << "outside of matrix range" << endl;
			return;
		}
		if (x < 0)
		{
			cout << "outside of matrix range" << endl;
			return;
		}
		if (matrix[x][x].value == val)
		{
			cout << "value already set" << endl;
			return;
		}
		matrix[x][x].value = val;
	}

	void addEdge(int x, int y, int val)
	{
		int i;
		int val1 = -1;
		int val2 = -1;
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == x)
			{
				val1 = i;
				break;
			}
		}
		if (val1 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == y)
			{
				val2 = i;
				break;
			}
		}
		if (val2 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		if (matrix[val1][val2].edgeval == val)
		{
			cout << "edge already exists" << endl;
			return;
		}
		matrix[val1][val2].edgeval = val;
		matrix[val2][val1].edgeval = val;
	}
	void removeEdge(int x, int y)
	{
		int i;
		int val1 = -1;
		int val2 = -1;
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == x)
			{
				val1 = i;
				break;
			}
		}
		if (val1 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == y)
			{
				val2 = i;
				break;
			}
		}
		if (val2 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		if (matrix[val1][val2].value <= 0)
		{
			cout << "edge doesnt exist" << endl;
			return;
		}
		matrix[x][y].edgeval = 0;
	}
	void setEdgeValue(int x, int y, int v)
	{
		int i;
		int val1 = -1;
		int val2 = -1;
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == x)
			{
				val1 = i;
				break;
			}
		}
		if (val1 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == y)
			{
				val2 = i;
				break;
			}
		}
		if (val2 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return;
		}
		if (matrix[val1][val2].edgeval == 0)
		{
			cout << "edge doesnt exist" << endl;
			return;
		}
		matrix[val1][val2].edgeval = v;
	}

	int getEdgeValue(int x, int y, int v)
	{
		int i;
		int val1 = -1;
		int val2 = -1;
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == x)
			{
				val1 = i;
				break;
			}
		}
		if (val1 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return -1;
		}
		for (i = 0; i < vertexcount; i++)
		{
			if (matrix[i][i].value == y)
			{
				val2 = i;
				break;
			}
		}
		if (val2 == -1)
		{
			cout << "vertex doesnt exist" << endl;
			return -1;
		}
		if (matrix[val1][val2].edgeval == 0)
		{
			cout << "edge doesnt exist" << endl;
			return -1;
		}
		return matrix[val1][val2].edgeval;
	}
	void printGraph()
	{
		int i, j;
		for (i = 0; i < vertexcount; i++)
		{
			for (j = 0; j < vertexcount; j++)
				cout << setw(2) << this->matrix[i][j].value << " ";
			cout << endl;
		}
		cout << endl;
	}
	void printGraphE()
	{
		int i, j;
		for (i = 0; i < vertexcount; i++)
		{
			for (j = 0; j < vertexcount; j++)
				cout << setw(2) << this->matrix[i][j].edgeval << " ";
			cout << endl;
		}
		cout << endl;
	}

	void savedata()
	{
		int i, j;
		ofstream plik("graph2");
		plik << "graph G {" << endl;
		for (i = 0; i < vertexcount; i++)
		{
			for (j = i; j < vertexcount; j++)
			{
				if (matrix[i][j].edgeval != 0)
				{
					if (matrix[i][j].mst == 1 || matrix[j][i].mst == 1)
					{
						plik << matrix[i][i].value << "--" << matrix[j][j].value << " [label=\"" << matrix[i][j].edgeval << "\", color=" << "GREEN" << "\];" << endl;
					}
					else
						plik << matrix[i][i].value << "--" << matrix[j][j].value << " [label=\"" << matrix[i][j].edgeval << "\"\];" << endl;
				}
			}
		}
		plik << "}";
		plik.close();
	}

	void printMST(int parent[])
	{
		cout << "Edge  Weight" << endl;
		for (int i = 1; i < vertexcount; i++)
		{
			cout << i << " - " << parent[i] << "  " << matrix[i][parent[i]].edgeval << endl;
			matrix[i][parent[i]].mst = 1;
		}
	}

	int minKey(int key[], bool mstSet[])
	{
		int min = INT_MAX;
		int index;

		for (int v = 0; v < vertexcount; v++)
		{
			if (mstSet[v] == false && key[v] < min)
			{
				min = key[v];
				index = v;
			}
		}
		return index;
	}

	void primMST()
	{

		int* parent = new int[vertexcount];
		int* key = new int[vertexcount];
		bool* usedVertices = new bool[vertexcount];
		for (int i = 0; i < vertexcount; i++)
		{
			key[i] = INT_MAX;
			usedVertices[i] = false;
		}
		key[0] = 0;
		parent[0] = -1;
		for (int i = 0; i < vertexcount - 1; i++)
		{
			int u = this->minKey(key, usedVertices);
			usedVertices[u] = true;
			for (int j = 0; j < vertexcount; j++)
				if (matrix[u][j].edgeval != 0 && usedVertices[j] == false && matrix[u][j].edgeval < key[j])
				{
					parent[j] = u,
						key[j] = matrix[u][j].edgeval;
				}
		}
		printMST(parent);
		savedata();
	}

};

int main()
{
	GraphP set;
	set.addVertex(0);
	set.addVertex(1);
	set.addVertex(2);
	set.addVertex(3);
	set.addVertex(4);
	set.addVertex(5);
	set.addVertex(6);
	set.addVertex(7);
	set.addVertex(8);
	set.addEdge(0, 1, 10);
	set.addEdge(0, 2, 12);
	set.addEdge(1, 2, 9);
	set.addEdge(1, 3, 8);
	set.addEdge(2, 4, 3);
	set.addEdge(2, 5, 1);
	set.addEdge(3, 4, 7);
	set.addEdge(3, 6, 8);
	set.addEdge(3, 7, 5);
	set.addEdge(3, 5, 10);
	set.addEdge(4, 5, 3);
	set.addEdge(5, 7, 6);
	set.addEdge(6, 8, 2);
	set.addEdge(6, 7, 9);
	set.addEdge(7, 8, 11);
	set.printGraph();
	set.printGraphE();
	set.primMST();
}


