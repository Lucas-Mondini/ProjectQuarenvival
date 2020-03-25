#include "QuarenvivalFunctions.h"
#include <iostream>
using namespace std;


void CallError(bool &running){
    running = false;
    GetError();
}
void GetError(){
    std::cout <<SDL_GetError() <<std::endl;
}


void eventListener(SDL_Event event, bool running, Player* player)
{
    switch(event.type)
    {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            keyListener(event, player);
                    break;
    }
}


void keyListener(SDL_Event event, Player* player)
{
        switch (event.key.keysym.sym)
        {
            case SDLK_LEFT:
            case SDLK_a:
                cout <<"esquerda\n";
                player->playerTextures.actualTexture = player->playerTextures.sLeft;
                player->actualstate = Player::state(2);
                if(!(player->coordinates.x < 0))
                    player->coordinates.x-=3;
            break;
            case SDLK_RIGHT:
            case SDLK_d:
                cout <<"direita\n";
                player->playerTextures.actualTexture = player->playerTextures.sRight;
                player->actualstate = Player::state(3);
                if(!(player->coordinates.x >= 600))
                    player->coordinates.x+=3;
            break;
            case SDLK_UP:
            case SDLK_w:
                cout <<"cima\n";
                player->playerTextures.actualTexture = player->playerTextures.sUp;
                player->actualstate = Player::state(1);
                if(!(player->coordinates.y < 0))
                    player->coordinates.y-=3;
            break;
            case SDLK_DOWN:
            case SDLK_s:
                cout <<"baixo\n";
                player->playerTextures.actualTexture = player->playerTextures.sDown;
                player->actualstate = Player::state(0);
                if(!(player->coordinates.y >= 800))
                    player->coordinates.y+=3;
            break;



        }

}

void setPlayerRenderBox (Player* player){
    if (player->actualstate == 0 || player->actualstate == 1){
        player->RenderBox.x=0;
        player->RenderBox.y=0;
        player->RenderBox.w=15;
        player->RenderBox.h=27;
    }
    else if(player->actualstate == 2 || player->actualstate == 3){
        player->RenderBox.x=0;
        player->RenderBox.y=0;
        player->RenderBox.w=8;
        player->RenderBox.h=27;
    }
}

void setPlayerSize(Player* player){
    player->coordinates.h = player->RenderBox.h*3;
    player->coordinates.w =  player->RenderBox.w*3;
}

void initPlayerLocalization(Player* player){
    player->coordinates.x = 0;
    player->coordinates.y = 0;
    player->coordinates.h = 27*3;
    player->coordinates.w = 15*3;
}
