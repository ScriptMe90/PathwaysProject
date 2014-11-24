#include "Flag.h"

Flag::Flag(int x, int y)
{
	m_flag = 0;
	m_x = x;
	m_y = y;
	m_w = 15;
	m_h = 10;
}



Flag::~Flag()
{
	SDL_FreeSurface(m_flag);
	m_flag = NULL;
}


void Flag::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}



bool Flag::loadImage(std::string filename, SDL_Surface* src)
{
	SDL_Surface* loaded = SDL_LoadBMP(filename.c_str());
	if (loaded == NULL)
	{
		std::cout << "Error loading flag!" << std::endl;
		return false;
	}
	else
	{
		m_flag = SDL_ConvertSurface(loaded, src->format, NULL);
		if (m_flag == NULL)
		{
			std::cout << "Error converting!" << std::endl;
			return false;
		}
	}
	return true;
}



void Flag::display(SDL_Surface* dest)
{
	SDL_Rect r;
	r.x = m_x;
	r.y = m_y;
	r.w = m_flag->w;
	r.h = m_flag->h;
	SDL_BlitSurface(m_flag, &r, dest, NULL);
}