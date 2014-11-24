#ifndef PATHING_H
#define PATHING_H
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include "LinkedList.h"
using namespace std;
#include <vector>
#include "MinHeap.h"

class Pathing
{
public:
	Pathing(int n);
	~Pathing();
	

	void calculatePath(int pointA, int pointB);

	void displayPath();

	LinkedList<int>* getPath();

private:
	vector<int> shortest;
	int nodeCount;
	Point* nodes;
	int** weights;
	MinHeap* heap;
};

#endif