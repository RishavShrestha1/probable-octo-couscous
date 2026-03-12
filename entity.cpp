#include "entity.h"

entity::entity(int x, int y, int h, int w) {
    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;
    velo_x = 0;
    velo_y = 0;
}


bool entity::checkCollision(entity& otherEntity) {
    SDL_Rect otherrect = otherEntity.getRect();
    SDL_Rect eRect = rect;

    if(eRect.x > otherrect.x + otherrect.w){
        return false;
    }
    if(eRect.y > otherrect.y + otherrect.h){
        return false;
    }
    if(otherrect.x > eRect.x + eRect.w) {
        return false;
    }
    if(otherrect.y > eRect.x + eRect.h){
        return false;
    }

    return false;

}
