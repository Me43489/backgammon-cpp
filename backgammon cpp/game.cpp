/**********************************
       Implementation of Class game
**********************************/
#include "texturemanager.hpp"
#include "texture_constants.hpp"
#include "game.hpp"
#include "display.hpp"
#include <iostream>
#include <iterator>
#include <string.h>


Game::Game(std::string title, int w, int h):event() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != NULL) {
        std::cerr<< "SDL was unable to be initalized" << SDL_GetError() << std::endl;
        running = false;
        Game::quit();
    }   
    Display::Create(w, h);
   
    // Loads the Textures
    TextureManager::Load("C:\\Users\\Me434\\source\\repos\\backgammon cpp\\Assets\\backgammon-board.png", BOARD);
    TextureManager::Load("C:\\Users\\Me434\\source\\repos\\backgammon cpp\\Assets\\red-triangle-down.png", R_TRIANGLE_DOWN);
    TextureManager::Load("C:\\Users\\Me434\\source\\repos\\backgammon cpp\\Assets\\red-triangle-up.png", R_TRIANGLE_UP);
    TextureManager::Load("C:\\Users\\Me434\\source\\repos\\backgammon cpp\\Assets\\red-triangle-up.png", W_TRIANGLE_UP);
    TextureManager::Load("C:\\Users\\Me434\\source\\repos\\backgammon cpp\\Assets\\red-triangle-up.png", W_TRIANGLE_DOWN);    
    

    running = true;
}

void Game::render() {
       
    SDL_RenderClear(Display::GetRenderer());
    SDL_SetRenderDrawColor(Display::GetRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(Display::GetRenderer());
    SDL_SetRenderDrawColor(Display::GetRenderer(),255, 0, 0, SDL_ALPHA_OPAQUE);
    
    SDL_Rect Board_Dest = { 0,0,960,768 };
    SDL_Rect Red_Triangle_Down = {36,24,73,300};
   
    Display::DrawTexture(TextureManager::Images[BOARD],Board_Dest);
    Display::DrawTexture(TextureManager::Images[R_TRIANGLE_DOWN], Red_Triangle_Down);

    //TextureManager::draw(BOARD, board_dest::h,board_dest::w, board_dest::x, board_dest::y);
    //TextureManager::draw(RED_CHIP, 100, 100, 100, 100);
    //SDL_RenderCopy(renderer,TextureManager::images["Board"].data, &texture->src, &texture->dest);
    //SDL_RenderCopy(renderer, texture->data, &texture->src, &texture->dest);
    Display::Present();
}

void Game::update() {
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit();
        }
    }
}

void Game::run() {
    while (running) {
        update();
        render();
    }
}


void Game::quit() {
    running = false;
}

/****************************
STATIC MEMBERS OF CLASS GAME:
*****************************/

