/**********************************
       Implementation of Class game
**********************************/
#include "game.hpp"

Game::Game(std::string title, int w, int h) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != NULL) {
        perror("SDL was unable to be initalized\n");
        SDL_GetError();
        exit(-1);
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) {
        perror("window was unable to be initalized\n");
        SDL_GetError();
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, NULL);
    if (renderer == NULL) {
        perror("renderer was unable to be initalized\n");
        SDL_GetError();
        exit(-1);
    }

    surface = SDL_GetWindowSurface(window);
    if (surface == NULL) {
        perror("surface was unable to initalized\n");
        SDL_GetError();
        exit(-1);
    }


    running = true;
}

void Game::render() {

    /* SDL_Rect x;// h w x ,y
     x.x = 0;
     x.y = 0;
     x.w = 1300;
     x.h = 700;*/

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 222, SDL_ALPHA_OPAQUE);


    SDL_RenderPresent(renderer);
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

SDL_Renderer* Game::getRenderer() {
    return renderer;
}
void Game::quit() {
    running = false;
    //SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    //SDL_DestroyTexture(texture);
}

/****************************
STATIC MEMBERS OF CLASS GAME:
*****************************/

SDL_Renderer* Game::renderer = NULL;