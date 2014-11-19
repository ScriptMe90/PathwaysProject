#include "Pathing.h"

Pathing::Pathing()
{
	weights = 0;
	paths = 0;
	nodeCount = 0;
	heap = 0;
	path = 0;
}


Pathing::Pathing(string filename, int numNodes)
{
	nodeCount = numNodes;
	
	weights = new int*[nodeCount];
	paths = new int*[nodeCount];

	for (int i = 0; i < nodeCount; ++i)
	{
		weights[i] = new int[nodeCount];
		paths[i] = new int[nodeCount];
	}

	heap = new MinHeap(nodeCount);

	shortestPath = new LinkedList<int>();
	
	ifstream is(filename, ios::in);
	
	int temp1, temp2, w;
	is >> temp1 >> temp2 >> w;
	
	while (is.good());
	{
		weights[temp1][temp2] = (w == 0) ? 0 : w;			
		paths[temp1][temp2] = 0;
		is >> temp1 >> temp2 >> w;
	}
}


Pathing::~Pathing()
{
	for (int i = 0; i < nodeCount; ++i)
	{
		delete[] paths[i];
		delete[] weights[i];
	}
	delete[] paths;
	delete[] weights;
	delete heap;
	delete shortestPath;
	nodeCount = 0;
}


void Pathing::calculatePath()
{

}


void Pathing::storePath()
{

}