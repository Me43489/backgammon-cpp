/*****************************
						Main 
******************************/
#include "include.hpp"
#include "game.hpp"
#include "texture_constants.hpp"

int main(int argc, char** argv) {

#ifdef JJJ_DEBUG
	char buffer[FILENAME_MAX];
	_getcwd(buffer, FILENAME_MAX);
	std::cout << "working dir : " << buffer << std::endl;
#endif // JJJ_DEBUG
	
	Game Backgammon = Game("Backgammon", 1280,1024);
	Backgammon.run();
	Backgammon.quit();

	return 0;
}