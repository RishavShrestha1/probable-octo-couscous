#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 420;

bool init();
bool loadshit();
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
        else {
            surfaceScreen = SDL_GetWindowSurface(window);
        }
    }
    return success;
}

bool loadshit(){
    bool success = true;
    image = SDL_LoadBMP("random.bmp");
    if(image == NULL) {
        std::cerr << "Unable to load image! SDL_Error : " <<SDL_GetError()<<std::endl;
        success = false;
    }
    return success;
}

void close() {
    SDL_FreeSurface(image);
    image = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

int main(int argc, char* argv[]){
    if(!init()){
        std::cerr <<"Failed to initialize! SDL_Error : "<<SDL_GetError() <<std::endl;
    }
    else {
        if(!loadshit()) {
            std::cerr << "Failed to load image! SDL_Error : "<<SDL_GetError() <<std::endl;
        }
        else{
            SDL_BlitSurface(image, NULL, surfaceScreen, NULL);
            SDL_UpdateWindowSurface(window);
            SDL_Event e;
            bool quit =false;while(quit == false){while(SDL_PollEvent (&e)) {if(e.type == SDL_QUIT){quit = true;}}}
        }
   }
   close();
   return 0;
}

