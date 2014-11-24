#ifndef FLAG_H
#define FLAG_H
#include <string>
#include <iostream>
#include "SDL.h"

class Flag
{
public:
	Flag(int x = 0, int y = 0);
	~Flag();
	void setPosition(int x, int y);
	bool loadImage(std::string filename, SDL_Surface* src);
	void display(SDL_Surface* dest);
private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	SDL_Surface* m_flag;
};



#endif