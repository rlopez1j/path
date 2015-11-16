#ifndef H_LINKEDLIST_H
#define H_LINKEDLIST_H

#include <iostream>
//#include "weightedGraph.h"
using namespace std;

template <class TYPE>
class inkedList:protected Graph
{
private:
	class node
	{
	public:
		TYPE graphComponent;
		node * next;

		node(TYPE x)
		{
			next = NULL;
			graphComponent = x;
		}
	};

	node * head, * tail;

	vertex * findV_(int x, node * p)
	{
		if (p == NULL)
			return;
		else if (x == p->graphComponent->address)
			return p->graphComponent;
		else
			return contains_h(x, p->next);
	}

public:
	linkedList()
	{
		head = NULL;
		tail = head;
	}

	void enqueue(TYPE component)
	{
		node * bby = new node(component);
		if (head == NULL)
		{
			head = bby;
			tail = head;
		}
		else
		{
			tail->next = bby;
			tail = bby;
		}
	}

	*vertex findV(int x) { return findV_(x, head); }
};

#endif
