#pragma once
/*****************************
			Instance of Game Class
******************************/

#include "space.hpp"
#include <string>
#include <stack>

class  Game {
private:

	static const uint32_t WIN_HEIGHT;
	static const uint32_t WIN_WIDTH;
	bool running;

	//Texture texture;
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Event event;
	static SDL_Renderer* renderer;

	void update();
	void render();

public:
	Game(std::string title, int w, int h);
	void run();
	void quit();
	static SDL_Renderer* getRenderer();
};