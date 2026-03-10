#include "entity.h"

bool init();
bool collisionChecker(SDL_Rect a, SDL_Rect b);
void close();
 
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* surfaceScreen = NULL;

SDL_Rect rect = {320, 210, 80, 80};

bool init() {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 420;
    bool success =  true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize video!" <<std::endl;
        success = false;
    }
    else {
        window = SDL_CreateWindow("Base Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(window== NULL && renderer == NULL) {
            std::cerr << "Unable to create window and/or renderer! SDL_Error : "<<SDL_GetError()<<std::endl; 
            success = false;
        }
        else {
            surfaceScreen = SDL_GetWindowSurface(window);
        }
    }
    return success;
}

bool collisionChecker(SDL_Rect a, SDL_Rect b) {

    if(a.x > b.x + b.w) {
        return false; //no collision
    }
    if(b.x > a.x + a.w) {
        return false;
    }
    if(a.y > b.y + b.h) {
        return false;
    }
    if(b.y > a.y + a.h) {
        return false;
    }

    return true;
}

void close() {
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

int main(int argc, char* argv[]){
    if(!init()){
        std::cerr <<"Failed to initialize! SDL_Error : "<<SDL_GetError() <<std::endl;
    }
    else {
            SDL_Event e;
            bool quit =false;
            while(quit == false){
                while(SDL_PollEvent (&e)){
                    if(e.type == SDL_QUIT){
                        quit = true;
                    }
                    else if(e.type == SDL_KEYDOWN){
                        switch(e.key.keysym.sym){
                            case SDLK_UP:
                            rect.y -= 30;
                            break;

                            case SDLK_DOWN:
                            rect.y += 30;
                            break;

                            case SDLK_LEFT:
                            rect.x -= 30;
                            break;

                            case SDLK_RIGHT:
                            rect.x += 30;
                            break;

                            default:
                            break;
                        }
                    }
                }
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &rect);

                SDL_RenderPresent(renderer);
            }
        }
   close();
   return 0;
}

