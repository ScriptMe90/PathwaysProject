/********************************************************************
Name:       Pandemic.h
Author(s):  Justin Brumley, Cory Feliciano, Joshua Ford.
Purpose:    Formal declaration of the Pandemic class.
********************************************************************/

#ifndef PANDEMIC_H
#define PANDEMIC_H
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "SDL.h"
#include "Pathing.h"

enum { CHINA = 0, GERMANY, RUSSIA, AUSTRALIA, FRANCE, ICELAND, BRAZIL, MEXICO, US};
class Pandemic
{
public:
	Pandemic();
	~Pandemic();

	int Execute();

	void drawPaths();
	void drawGraph();

private:
	Pathing* m_p;
	SDL_Surface* m_wndSurf;
	SDL_Surface* m_graph;
	SDL_Window* m_wnd;
	vector<int> m_path;
	bool m_running;
	int m_currNode;

};

#endif