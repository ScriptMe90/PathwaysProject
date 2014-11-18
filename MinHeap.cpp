#include "MinHeap.h"

Node::Node()
	: data(-1)
{
	left = 0;
	right = 0;
}


Node::Node(Node* l, Node* r, int dat)
	: left(l), right(r), data(dat)
{

}




MinHeap::MinHeap()
{
	root = 0;
}


MinHeap::~MinHeap()
{
	//no
}


void MinHeap::insert(int val)
{
	Node* temp = root;
	Node* temp2 = temp;
	if (temp != 0)
	{
		Node* newNode;
		while (temp != 0)
		{
			
		}
		
	}
	else
		root = new Node(0, 0, val);
}


void MinHeap::removeMin()
{

}