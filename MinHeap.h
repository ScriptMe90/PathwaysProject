#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <limits>
using namespace std;

/*class Point
{
public:
	Point();
	Point(int dat);
	int getData();
	void setData(int dat);
	bool isKnown();
private:
	Point* next;
	int data;
	bool known;
};*/

enum {CHINA, US, GERMANY, FRANCE, RUSSIA, BRAZIL, MEXICO, ICELAND, AUSTRALIA};

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
	//Point* curr;
	int curr;
	Point** heap;
};

#endif
