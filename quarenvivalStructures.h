#ifndef QUARENVIVALSTRUCTURES_H
#define QUARENVIVALSTRUCTURES_H

#include "quarenvivalIncludes.h"

enum PROP_ID{
    BLUE_COUCH,
    REFRIGERATOR,
    BED
};

struct dTextures{

    SDL_Texture* Actual_Day;
    SDL_Texture* Day_1;
    SDL_Texture* Day_2;
    SDL_Texture* Day_3;
    SDL_Texture* Day_4;
    SDL_Texture* Day_5;
    SDL_Texture* Day_6;
    SDL_Texture* Day_7;

    SDL_Texture* iDay_1;
    SDL_Texture* iDay_2;
    SDL_Texture* iDay_3;
    SDL_Texture* iDay_4;
    SDL_Texture* iDay_5;
    SDL_Texture* iDay_6;
    SDL_Texture* iDay_7;

    SDL_Rect dSource;
    SDL_Rect dDestiny;
};

struct Prop
{
    PROP_ID id;
    SDL_Texture* propTexture;
    SDL_Rect propRenderBox;
    SDL_Rect propCoordinate;

};


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

struct Acceleration{
    int x;
    int y;
};


struct Player {
    enum job{
        NO_JOB,
        DOCTOR,
        PROGRAMMER,
        BUILDER,
        YOUTUBER,
        CHEF
    };

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
    Acceleration playerAcceleration;
    state actualstate;
    SDL_Rect RenderBox;
    SDL_Rect coordinates;
    pTextures playerTextures;
    int Cash;
    bool sick;
    int hungry;
    int food;

};


#endif // QUARENVIVALSTRUCTURES_H
