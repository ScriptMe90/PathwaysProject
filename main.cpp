#include <iostream>
#include "Pandemic.h"
using namespace std;

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Pandemic p;
	
	return p.Execute();
}