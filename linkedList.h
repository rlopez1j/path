#ifndef H_LINKEDLIST_H
#define H_LINKEDLIST_H

#include <iostream>	
using namespace std;

template <class TYPE>
class linkedList//:Graph
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

	vertex * findV_(int x, node * p) //check if need
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

	*Graph::vertex findV(int x) { return findV_(x, head); } //possible <vertex*> needed
};

#endif
