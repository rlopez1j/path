#ifndef H_CHAININGTABLE_H
#define H_CHAININGTABLE_H

#include "linkedList.h"
#include "weightedGraph.h"
#include <iostream>
#include <string>
using namespace std;
//class Graph;
//template <class TYPE> 
class chainingTable//:public Graph
{
private:
	//hash table conists of a table of lists
	linkedList * table;
	//size of table
	int capacity;

	//number of items in hash table
	int numItems;

	int createKey(vertex* v) { return 37* v->address % capacity; }
	int createKey(edge e) { return (e.start->addres * 37) + (e.end->address * 37) % capacity; }
	int createKey(int addss) { return addrss%capacity; }

	void insert_(int key, TYPE t)
	{
		table[key].enqueue(t);
		numItems++;
	}


public:
	chainingTable()
	{
		capacity = 101;
		table = new linkedList[capacity];
		numItems = 0;
	}

	chainingTable(int cap)
	{
		capacity = cap;
		table = new linkedList[capacity];
		numItems = 0;
	}
	
	void insert(edge e) { insert_(createKey<edge>(e),e); }
	void insert(vertex* v) { insert_(createKey<vertex*>(v), v); }

	int size() { return capacity; }

	vertex * findVertex(int address)
	{
		int key = createKey(address);
		return table[key].findV(x);
	}

	//overloadbracket operator
	TYPE& operator[](int i) { return table[i]; }
};

#endif
