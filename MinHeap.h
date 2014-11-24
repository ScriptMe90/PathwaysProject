#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <limits>
using namespace std;

struct Point
{
	int id;
	bool visited;
	int dist;
};


class MinHeap
{
public:
	MinHeap();
	MinHeap(int sz);
	~MinHeap();
	
	void insert(Point& val);
	Point removeMin();

	bool empty();

	void debugprint();
private:
	int siz;
	//Point* curr;
	int curr;
	Point** heap;
};

#endif