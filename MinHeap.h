#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
using namespace std;

class MinHeap
{
public:
	MinHeap();
	MinHeap(int sz);
	~MinHeap();
	
	void insert(int val);
	void removeMin();

	void debugprint();
private:
	int siz;
	int curr;
	int* heap;
};

#endif