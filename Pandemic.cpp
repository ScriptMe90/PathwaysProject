#include "Pandemic.h"

Pandemic::Pandemic()
{
	m_running = true;
	m_p = new Pathing(9);
	SDL_Init(SDL_INIT_EVERYTHING);
	m_wnd = SDL_CreateWindow("Pandemic Analysis", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 488, SDL_WINDOW_SHOWN);

	m_wndSurf = SDL_GetWindowSurface(m_wnd);
	m_graph = SDL_LoadBMP("Resources/world.bmp");
	m_p->calculatePath(0, 8);
	m_path = m_p->getPath();
	m_currNode = m_path.size() - 2;
}


Pandemic::~Pandemic()
{
	delete m_p;
	SDL_FreeSurface(m_graph);
	SDL_FreeSurface(m_wndSurf);
}


int Pandemic::Execute()
{
	while (m_running)
	{
		drawGraph();
		SDL_Event ev;
		
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			{
				m_running = false;
			}
			if (ev.key.keysym.sym == SDLK_DOWN)
			{
				while (m_currNode >= 0)
					drawPaths();
			}
		}
		
		SDL_UpdateWindowSurface(m_wnd);
		//system("CLS");
	}
	return 0;
}


void Pandemic::drawPaths()
{
	if (m_currNode >= 0)
	{
		int curr = m_path[m_currNode];
		cout << "**************************" << endl;
		switch (curr)
		{
		case CHINA:
			cout << "*     China              *   --->" << endl;
			break;
		case GERMANY:
			cout << "*     Germany            *   --->" << endl;
			break;
		case RUSSIA:
			cout << "*     Russia             *   --->" << endl;
			break;
		case AUSTRALIA:
			cout << "*     Australia          *   --->" << endl;
			break;
		case FRANCE:
			cout << "*     France             *   --->" << endl;
			break;
		case ICELAND:
			cout << "*     Iceland            *   --->" << endl;
			break;
		case BRAZIL:
			cout << "*     Brazil             *   --->" << endl;
			break;
		case MEXICO:
			cout << "*     Mexico             *   --->" << endl; 
			break;
		case US:
			cout << "*     US                 *   --->" << endl;
			break;
		}
		cout << "**************************" << endl;
		m_currNode--;
	}
}


void Pandemic::drawGraph()
{
	SDL_BlitSurface(m_graph, NULL, m_wndSurf, NULL);
}