#include "Pandemic.h"

int main()
{
	/*
	Pandemic pan;
	return pan.run();*/
	Pathing p(5);

	p.calculatePath(0, 4);
	p.displayPath();

	system("PAUSE");

	return 0;
}
