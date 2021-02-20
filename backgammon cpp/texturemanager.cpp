#include <string>
#include <iostream> 
#include "texturemanager.hpp"
#include "game.hpp"


void TextureManager::Destroy()
{
    for (auto i : TextureManager::Images) SDL_DestroyTexture(i.second);
}

bool TextureManager::Load(std::string filename, std::string name)
{
    SDL_Texture* texture = IMG_LoadTexture(Display::GetRenderer(), filename.c_str());
    if (texture == nullptr) {
        std::cout << "Failed to load:" << filename << "\n";
    }
    Images[name] = texture;
    return false;
}

SDL_Texture* TextureManager::Get(std::string name, int gridSizeX, int gridSizeY, int x, int y, SDL_Rect& dest) {
    SDL_Texture* tex = Images[name];
    if (tex == nullptr) return tex;
    dest.x = gridSizeX * x;
    dest.y = gridSizeY * y;
    dest.w = gridSizeX;
    dest.h = gridSizeY;
    return tex;
}

SDL_Texture* TextureManager::Get(std::string name, SDL_Rect& dest)
{
    SDL_Texture* tex = Images[name];
    Uint32 fmt;
    int acs;
    dest.x = 0;
    dest.y = 0;
    SDL_QueryTexture(tex, &fmt, &acs, &dest.w, &dest.h);

    return tex;
}

SDL_Texture* TextureManager::Get(std::string name)
{
    SDL_Texture* tex = Images[name];
    /*Uint32 fmt;
    int acs;
    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    SDL_QueryTexture(tex, &fmt, &acs, &dest.w, &dest.h);*/
    return tex;
}

//Statics
std::map<std::string, SDL_Texture*> TextureManager::Images;





/*
/*Texture::Texture(std::string filename,std::string name) {
    SDL_Surface* surface;

    if (IMG_Init(IMG_INIT_PNG) == NULL) {
        perror("Error: Couldn`t initalize image");
        SDL_GetError();
        exit(-1);
    }
    surface = IMG_Load(filename.c_str());
    if (surface == NULL) {
        perror("Error: Couldn`t initalize surface");
        SDL_GetError();
        exit(-1);
    }
    Texture::data = SDL_CreateTextureFromSurface(Game::getRenderer(), surface);
    if (Texture::data == NULL) {
        perror("Error: Couldn`t initalize texture");
        SDL_GetError();
        exit(-1);
    }
    Texture::path = filename;
    Texture::src = { NULL };
    Texture::dest = { NULL };
   
    TextureManager::images.insert(std::pair <std::string,Texture>("f",Texture::))
}*/
//void TextureManager::Load(std::string filename) {
    
//}
/*Texture TextureManager::Load(std::string filename) {
   

    if (IMG_Init(IMG_INIT_PNG) == NULL) {
        perror("Error: Couldn`t initalize image");
        SDL_GetError();
        exit(-1);
    }
    surface = IMG_Load(filename.c_str());
    if (surface == NULL) {
        perror("Error: Couldn`t initalize surface");
        SDL_GetError();
        exit(-1);
    }
    Game::setTexture(SDL_CreateTextureFromSurface(Game::getRenderer(), surface));
    if (Game::getTexture()->data== NULL) {
        perror("Error: Couldn`t initalize texture");
        SDL_GetError();
        exit(-1);
    }
    SDL_FreeSurface(surface);
   
   //Game::getTexture()->dest = { 0,0,1200,720 };
   Game::getTexture()->src = {board_src::h,board_src::w,board_src::x,board_src::y };  
   images.insert(std::pair<std::string, Texture>(BOARD, *Game::getTexture()));

    Game::getTexture()->src = {0,0,660,1000};
    images.insert(std::pair<std::string, Texture>(RED_CHIP, *Game::getTexture()));

     //images[0];
    // set rest of textures here
     return *Game::getTexture(); // can get messy passing by value here, theres an internal pointer to An Sdl_texture
}
void TextureManager::draw(const char* name, int h, int w, int x, int y) {
    Game::getTexture()->dest ={ h, w, x, y };
    SDL_RenderClear(Game::getRenderer());
    SDL_RenderCopy(Game::getRenderer(), TextureManager::images[std::string (name)].data, &Game::getTexture()->src, &Game::getTexture()->dest);
}

/*void TextureManager::SetTextures() {
    texture.src = { 0,0,1450,850 };
    images.insert(std::pair<std::string, Texture>("Board", texture));
    /*texture.src = {}
    images.insert(std::pair<std::string, Texture>("Chip", texture));
    }
Texture* TextureManager::getTexture() {
    return texture;
}*/

/*void TextureManager::setTexture(std::string name,SDL_Texture* texture) {
    Texture::data = texture;
    Texture::path
    //images.emplace()
}*/
/*void TextureManager::Load(std::string filename) {
    Texture::path = filename;
    Texture::
}

****************************
STATIC MEMBERS OF TEXTUREMANAGER:
*****************************

std::map<std::string, Texture> TextureManager::images;*/