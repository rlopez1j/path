#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>
#include "chainingTable.h"
#include "minHeap.h"
using namespace std;

class Graph
{
protected:
	//template <class TYPE> class linkedList;
	//template <class TYPE> class chainingTable;
	//class minHeap;	
	class vertex;
	class edge;

	class vertex //basically, a node...
	{
	public:
		vertex() { visited = false; }
		vertex(int c, int adrss)
		{
			cost = c;
			address = adrss;
			visited = false;
		}
		
		int address;
		int weight;
		int cost;
		
		chainingTable<edge> edgeList;
		bool visited;
		vertex * predecessor;

	};

	class edge
	{
	public:
		edge(vertex *v, vertex*u, int w)
		{
			start=v;
			end=u;
			weight = w;
		}

		int weight;
		vertex * start;
		vertex * end;
	};

	chainingTable<vertex*> vertexList;

	vertex * findVertex(int addrs) { return vertexList.findVertex(addrs); }
	int weight(vertex *v, vertex *u) { return v->weight + u->weight; }
	void relax(vertex * v, vertex * u,int i, minHeap h)
	{
		if(v->weight > u->weight+weight(v,u))
		{
			v->weight = v->weight + weight(v,u); 
			h.decreaseKey(i, v->weight);	//fixes heap
			v->predecessor = u;
		}
	}
public:
	void addVertex(int cost, int address) 
	{ vertexList.insertVert(new vertex(cost, address)); }

	void addEdge(int x, int y, int w) 
	{
		vertex * u = findVertex(x);
		vertex * v = findVertex(y);

		edge e(u,v,w);
		u->edgeList.insertEdge(e);
	}

	void dijktra(vertex *v)
	{
		minHeap heap;
		vertex * x;
		//1)
		v->weight = 0;
		for (int i = 0; i < vertexList.size(); i++) //iterate thru vertices
		{
			if(v->address != vertexList[i]->address) //if not starting point make weight inf
				vertexList[i]->weight = INFINITY;
			heap.insert(vertexList[i]); //add all to heap
		}
		//2)
		while(!heap.empty())
		{
			x = heap.extractMin();

			for (int i = 0; i < x->edgeList.size(); i++) //find way to iterate thru hashTable
				relax(x->edgeList[i]->start,x->edgeList[i]->end,i,heap);
		}
	}

	void readIn() //figure out how to enter data;
	{
		ifstream f;
		f.open("NYC.txt");
		int numVertices;
		int numEdges;
		int cost, weight, location;

		f >> numVertices;
		f >> numEdges;

		chainingTable<vertex*> vL(numVertices);
		vertexList = vL;

		while (!f.eof())
		{
			f >> cost;
			f >> weight;
			f >> location;
			addVertex(cost, location); //not correct. figure out what is being inserted
		}
	}

	void findPath(int a, int b) //runs all things by calling this
	{
		//readI();
		//diej();
		//whatever else is left
	}
};
