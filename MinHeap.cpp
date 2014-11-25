#include "MinHeap.h"


MinHeap::MinHeap()
{
	heap = 0;
	curr = 0;
	siz = 0;
}


MinHeap::MinHeap(int sz)
{
	siz = sz * 2;
	heap = new Point*[siz];
	for (int i = 0; i < siz; ++i)
	{
		heap[i] = new Point;
		heap[i]->dist = 0;
		heap[i]->id = 0;
		heap[i]->visited = false;
	}
	curr = 0;
}


MinHeap::~MinHeap()
{
	for (int i = 0; i < siz; ++i)
	{
		if (heap[i] != 0)
			delete heap[i];
	}

	delete[] heap;
	curr = 0;
	siz = 0;
}


void MinHeap::insert(Point& val)
{
	if (siz != 0 && curr <= siz - 1)
	{
		int node = ++curr;
		while (heap[node / 2]->dist > val.dist)
		{
			*heap[node] = *heap[node / 2];
			node = node / 2;
		}
		if (curr < siz)
		{
			*heap[node] = val;
		}
	}
	//cout << "Current is now: " << curr << endl;
}


Point MinHeap::removeMin()
{
	Point result;
	result.dist = 0;
	result.id = -1;
	result.visited = false;
	if (heap[1]->dist == -1)
	{
		return result;
	}
	
	result = *heap[1];
	*heap[1] = *heap[curr--];
	heap[curr + 1]->dist = 0;
	//////////////////////////////////////////////////

	int child;
	int hole = 1;

	Point temp = *heap[hole];

	while (hole * 2 <= curr)
	{
		child = hole * 2;
		if (child != curr && heap[child + 1]->dist < heap[child]->dist)
			++child;

		if (heap[child]->dist < temp.dist)
		{
			Point tmp2 = *heap[hole];
			*heap[hole] = *heap[child];
			*heap[child] = tmp2;
		}
		else
			break;

		hole = child;
	}
	*heap[hole] = temp;

	return result;
}



void MinHeap::debugprint()
{
	for (int i = 0; i < siz; ++i)
	{
		int temp = heap[i]->dist;
		cout << temp << endl;
	}
}
