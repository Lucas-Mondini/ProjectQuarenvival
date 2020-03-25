#ifndef QUARENVIVALSTRUCTURES_H
#define QUARENVIVALSTRUCTURES_H

#include "quarenvivalIncludes.h"


struct pTextures{

    SDL_Texture* actualTexture;

    //stand textures
    SDL_Texture* sDown;
    SDL_Texture* sUp;
    SDL_Texture* sLeft;
    SDL_Texture* sRight;
    SDL_Texture* sLeftDown;
    SDL_Texture* sRightDown;
    SDL_Texture* sLeftUp;
    SDL_Texture* sRightUp;
    //stand textures

    //running textures
    SDL_Texture* rDown;
    SDL_Texture* rUp;
    SDL_Texture* rLeft;
    SDL_Texture* rRight;
    SDL_Texture* rLeftDown;
    SDL_Texture* rRightDown;
    SDL_Texture* rLeftUp;
    SDL_Texture* rRightUp;
    //running textures


};



struct Player {
    enum state{
        STANDING_DOWN,
        STANDING_UP,
        STANDING_LEFT,
        STANDING_RIGHT,
        STANDING_LEFT_DOWN,
        STANDING_RIGHT_DOWN,
        STANDING_LEFT_UP,
        STANDING_RIGHT_UP,

        RUNNING_DOWN,
        RUNNING_UP,
        RUNNING_LEFT,
        RUNNING_RIGHT,
        RUNNING_LEFT_DOWN,
        RUNNING_RIGHT_DOWN,
        RUNNING_LEFT_UP,
        RUNNING_RIGHT_UP
    };
    state actualstate;
    SDL_Rect RenderBox;
    SDL_Rect coordinates;
    pTextures playerTextures;

};


#endif // QUARENVIVALSTRUCTURES_H
