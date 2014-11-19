#ifndef PATHING_H
#define PATHING_H
#include <string>
#include <fstream>
#include "LinkedList.h"
using namespace std;

#include "MinHeap.h"

class Pathing
{
public:
	Pathing();
	Pathing(string filename, int numNodes);
	~Pathing();

	void calculatePath();

	LinkedList<int>* getPath();

private:
	void storePath();
	int** weights;
	int** paths;
	int nodeCount;
	MinHeap* heap;
	LinkedList<int>* shortestPath;
};

#endif