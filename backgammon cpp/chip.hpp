#pragma once
/*****************************
			Instance of Chip Class
******************************/
#include <SDL.h>

class Chip {
private:
	SDL_Rect src;
	SDL_Rect dest;
	bool color;
	bool inqueue;
public:
	void move();
	void die();
	void capture();
};
