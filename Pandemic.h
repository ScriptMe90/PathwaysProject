#ifndef PANDEMIC_H
#define PANDEMIC_H
#include "MinHeap.h"
#include "Pathing.h"
#include "FrontEnd.h"

class Pandemic
{
public:
	Pandemic();
	int run();
private:
	Pathing* path;
	FrontEnd* front;
};


#endif