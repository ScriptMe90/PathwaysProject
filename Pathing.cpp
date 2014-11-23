#include "Pathing.h"


Pathing::Pathing()
{
	string line;
	nodeCount = 14; //for testing purposes

	heap = new MinHeap(nodeCount);

	weights = new int*[nodeCount];

	shortestPath = new int[nodeCount];

	for (int i = 0; i < nodeCount; ++i)
	{
		weights[i] = new int[nodeCount];
		shortestPath[i] = 0;
	}

	for (int i = 0; i < nodeCount; ++i)
	{
		for (int j = 0; j < nodeCount; ++j)
		{
			weights[i][j] = 0;
		}
	}
	
	ifstream fin("data.txt");
	int ind1, ind2, w;
	//fin >> ind1 >> ind2 >> w;
	while (fin.good())
	{
		fin >> ind1 >> ind2 >> w;
		weights[ind1][ind2] = w;
	}

	//build nodes
	nodes = new Point[nodeCount];
	for (int i = 0; i < nodeCount; ++i)
	{
		nodes[i].id = i;
		nodes[i].dist = 0;
		nodes[i].visited = false;
	}
}


Pathing::~Pathing()
{
	for (int i = 0; i < nodeCount; ++i)
		delete[] weights[i];
	
	delete[] weights;
	delete heap;
	delete shortestPath;
	nodeCount = 0;
}


void Pathing::calculatePath(int pointA, int pointB)
{
	//cout << pointB << " ";
	nodes[pointA].dist = 0;
	heap->insert(nodes[pointA]);
	shortestPath[pointA] = pointA;

	for (int i = 0; i < nodeCount; ++i)
	{
		Point min = heap->removeMin();
		//cout << "current min id: " << min.id << " current min dist: " << min.dist << " current min visited: " << min.visited << endl;
		//cout << "outer i: " << i << endl;
		while (min.visited)  //if the node has already been visited, discard it.
		{
			min = heap->removeMin();
		}
		min.visited = true;

		for (int j = 0; j < nodeCount; ++j)
		{
			//cout << "weights[min.id][i] is " << weights[min.id][i] << endl;
			//cout << "i is: " << i << endl;
			if (weights[min.id][j] > 0) //testing current node's connections
			{
				int nodeweight = nodes[min.id].dist + weights[min.id][j];

				if (!nodes[j].visited) //if the node hasn't been seen before
				{ //then check to see if the distance is smaller

					if (nodes[j].dist > nodeweight)
					{
						nodes[j].dist = nodeweight; //update weight
						shortestPath[i] = nodes[j].id;
						cout << "id: " << nodes[j].id << endl;
						cout << "nodeweight after replace: " << nodeweight << endl;
					}
					
					else
					{
						
						nodes[j].dist = nodeweight;
						shortestPath[i] = nodes[j].id;
						cout << "id: " << nodes[j].id << endl;
						cout << "nodeweight after no replace: " << nodeweight << endl;
					}
	
				}
				heap->insert(nodes[j]);		//push new weight onto heap
			}
			//else
				//cout << "Skipped inner loop!" << endl;
		}
	}

	/*
		for all adjacent nodes to curr
			if smallest
				push weight onto heap
				update current
				update pathing table */
}	


void Pathing::displayPath()
{
	for (int i = 0; i < nodeCount; ++i)
	{
		if (shortestPath[i] != 0)
		{
			cout << shortestPath[i] << " ";
		}
	}
}