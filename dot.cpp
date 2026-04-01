#include "entity.h"

const int SCREEN_HEIGHT = 420;
const int SCREEN_WIDTH = 640;

Dot::Dot() {
    mPosX = 0;
    mPosY = 0;

    mVelX = 0;
    mVelY= 0;

}

void Dot::HandleEvent(SDL_Event& e) {
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {

        switch(e.key.keysym.sym){
            case SDLK_UP: mVelY -= DOT_VELOCITY; break;
            case SDLK_DOWN: mVelY += DOT_VELOCITY; break;
            case SDLK_LEFT: mVelX -= DOT_VELOCITY; break;
            case SDLK_RIGHT: mVelX += DOT_VELOCITY; break;
        }
    }
    else if(e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch(e.key.keysym.sym){
            case SDLK_UP: mVelY += DOT_VELOCITY; break;
            case SDLK_DOWN: mVelY -= DOT_VELOCITY; break;
            case SDLK_LEFT: mVelX += DOT_VELOCITY; break;
            case SDLK_RIGHT: mVelX -= DOT_VELOCITY; break;
        }
    }
}

void Dot::move(){
    mPosX += mVelX;
    if((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH)) {
        mPosX -= mVelX;
    }

    mPosY += mVelY;
    if((mPosY < 0) || (mPosY + DOT_WIDTH > SCREEN_HEIGHT)) {
        mPosY -= mVelY;
    }
}

void Dot::update(){}

bool Dot::render(SDL_Renderer* renderer) {
    SDL_Rect dotRect = {mPosX, mPosY, 10, 10}; 
    SDL_SetRenderDrawColor(renderer, 255, 0 , 0 , 255);
    SDL_RenderFillRect(renderer, &dotRect);
    return true;
}