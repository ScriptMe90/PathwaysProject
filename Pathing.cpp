#include "Pathing.h"


Pathing::Pathing(int n)
{
	string line;
	nodeCount = n;

	heap = new MinHeap(nodeCount + 1);

	weights = new int*[nodeCount];

	for (int i = 0; i < nodeCount; ++i)
		weights[i] = new int[nodeCount];

	for (int i = 0; i < nodeCount; ++i)
		for (int j = 0; j < nodeCount; ++j)
			weights[i][j] = 0;

	
	ifstream fin("data.txt");
	int ind1, ind2, w;
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
		nodes[i].dist = numeric_limits<int>::max() / 2;
		nodes[i].visited = false;
	}
}


Pathing::~Pathing()
{
	for (int i = 0; i < nodeCount; ++i)
		delete[] weights[i];
	
	delete[] weights;
	delete heap;
	nodeCount = 0;
}


void Pathing::calculatePath(int pointA, int pointB)
{
	//cout << pointB << " ";
	nodes[pointA].dist = 0;
	heap->insert(nodes[pointA]);

	for (int i = 0; i < nodeCount; ++i)
	{
		Point min = heap->removeMin();
		//cout << "outer i: " << i << endl;
		while (min.visited)  //if the node has already been visited, discard it.
		{
			min = heap->removeMin();
		}
		min.visited = true;

		//cout << "current min id: " << min.id << " current min dist: " << min.dist << endl;

		for (int j = 0; j < nodeCount; ++j)
		{
			if (weights[min.id][j] > 0) //testing current node's connections
			{
				int nodeweight = nodes[min.id].dist + weights[min.id][j];

				if (!nodes[j].visited)	//if the node hasn't been seen before
				{						//then check to see if the distance is smaller
					if (nodes[j].dist > nodeweight)
						nodes[j].dist = nodeweight; //update weight
				}
				heap->insert(nodes[j]);		//push new weight onto heap
			}
		}
	}

	//finding path based on node information
	int smallest = nodes[pointB].id;
	shortest.push_back(nodes[pointB].id);
	int curr = pointB;

	while (curr != pointA)
	{
		int j;
		for (j = nodeCount - 1; j >= 0; --j)
		{
			if (weights[j][curr] > 0)
			{
				int check;
				if (nodes[j].id == pointA)
					check = pointA;
				else
					check = nodes[j].dist;

				if (check + weights[j][curr] == nodes[curr].dist)
					smallest = nodes[j].id;	
			}
		}
		shortest.push_back(nodes[smallest].id);
		curr = smallest;
	}
	shortest.push_back(pointA);
}	


vector<int>& Pathing::getPath()
{
	return shortest;
}


void Pathing::displayPath()
{
	for (int i = 0; i < shortest.size(); ++i)
	{
		if (shortest[i] != 0)
		{
			cout << shortest[i] << " ";
		}
	}
}