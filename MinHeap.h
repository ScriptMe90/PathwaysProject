/********************************************************************
Name:       MinHeap.h
Author(s):  Justin Brumley, Cory Feliciano, Joshua Ford.
Purpose:    Formal declaration of the minheap class and point struct.
********************************************************************/

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

	void debugprint();
private:
	int siz;
	int curr;
	Point** heap;
};

#endif