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
	Pathing();
	~Pathing();
	//vector<int> shortest;

	void calculatePath(int pointA, int pointB);

	void displayPath();

	LinkedList<int>* getPath();

private:
	void storePath();
	int nodeCount;
	Point* nodes;
	int** weights;
	MinHeap* heap;
	int* shortestPath;
};

#endif