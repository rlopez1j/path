#ifndef H_CHAININGTABLE_H
#define H_CHAININGTABLE_H

#include "linkedList.h"
#include <iostream>
#include <string>
using namespace std;
//class Graph;

template <class TYPE> 
class chainingTable:protected Graph
{
private:
	//hash table conists of a table of lists
	linkedList * table;
	//size of table
	int capacity;

	//number of items in hash table
	int numItems;

	int createKey(vertex* v) { return 37* v->address % capacity; }
	int createKey(edge e) { return (e.start->address * 37) + (e.end->address * 37) % capacity; }
	int createKey(int addss) { return addss%capacity; }

	void insert(int key, TYPE e)
	{
		table[key].enqueue(e);
		numItems++;
	}
	/*void insert(int key, vertex * v)
	{
		table[key].enqueue(e);
		numItems++;
	}*/


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
	
	void insert(edge e) { insert_(createKey(e),e); }
	void insert(vertex* v) { insert_(createKey(v), v); }

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
