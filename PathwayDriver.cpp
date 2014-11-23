#include "Pandemic.h"

int main()
{
	/*
	Pandemic pan;
	return pan.run();*/
	Pathing p;

	p.calculatePath(0, 5);
	p.displayPath();

	system("PAUSE");

	return 0;
}
