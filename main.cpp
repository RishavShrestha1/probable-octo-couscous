#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 420;

bool init();
void close();

SDL_Window* window = NULL;
SDL_Surface* surfaceScreen = NULL;

SDL_Surface* image = NULL;

bool init() {
    bool success =  true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize video!" <<std::endl;
        success = false;
    }
    else {
        window = SDL_CreateWindow("Base Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window== NULL) {
            std::cerr << "Unable to create window! SDL_Error : "<<SDL_GetError()<<std::endl; 
            success = false;
        }
    }

}