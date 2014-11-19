#include "MinHeap.h"


MinHeap::MinHeap()
{
	heap = 0;
	curr = -1;
	siz = 0;
}


MinHeap::MinHeap(int sz)
{
	siz = sz * 2;
	heap = new int[siz];
	for (int i = 0; i < siz; ++i)
	{
		heap[i] = 0;
	}
	curr = 0;
}


MinHeap::~MinHeap()
{
	delete[] heap;
	curr = -1;
	siz = 0;
}


void MinHeap::insert(int val)
{
	if (siz != 0)
	{
		curr++;
		int node = curr;
		while (heap[node / 2] > val)
		{
			heap[node] = heap[node / 2];
			node = node / 2;
		}
		heap[node] = val;
	}
}


void MinHeap::removeMin()
{

}


void MinHeap::debugprint()
{
	for (int i = 0; i < siz; ++i)
	{
		cout << heap[i] << endl;
	}
}
