/*****************************
						Main 
******************************/
#include "include.hpp"
#include "game.hpp"

int main(int argc, char** argv) {

	char buffer[FILENAME_MAX];
	_getcwd(buffer, FILENAME_MAX);
	std::cout << "working dir : " << buffer;

	Game Backgammon = Game("Backgammon", 1200, 720);
	Backgammon.run();
	Backgammon.quit();

	return 0;
}
