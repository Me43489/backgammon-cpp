#pragma once
/*****************************
			Instance of Game Class
******************************/

#include <string>
#include <stack>
#include "texturemanager.hpp"
#include "space.hpp"
#include "display.hpp"

class  Game {
private:

	bool running; 
	SDL_Event event;

	void update();
	void render();

public:
	Game(std::string title, int w, int h);
	void run();
	void quit();
};
