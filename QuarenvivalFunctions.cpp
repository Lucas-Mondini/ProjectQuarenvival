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
        case SDL_KEYUP:
            player->playerAcceleration.x = player->playerAcceleration.y = 0;
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
                if(player->playerAcceleration.x > - 6)
                    player->playerAcceleration.x-= 3;
            break;
            case SDLK_RIGHT:
            case SDLK_d:
                cout <<"direita\n";
                if(player->playerAcceleration.x < 6)
                    player->playerAcceleration.x+= 3;
            break;
            case SDLK_UP:
            case SDLK_w:
                cout <<"cima\n";
                if(player->playerAcceleration.y > - 6)
                    player->playerAcceleration.y-= 3;
            break;
            case SDLK_DOWN:
            case SDLK_s:
                cout <<"baixo\n";
                if(player->playerAcceleration.y < 6)
                    player->playerAcceleration.y+= 3;
            break;



        }

}



void setPlayerLocation (Player* player){
    if((player->playerAcceleration.x > 0 && player->coordinates.x < 800 - player->coordinates.w ) || (player->playerAcceleration.x < 0 && player->coordinates.x > 0) ){

        player->coordinates.x += player->playerAcceleration.x;
    }
    else
        player->playerAcceleration.x=0;

    if( (player->playerAcceleration.y > 0 && player->coordinates.y < 600 - player->coordinates.h) || (player->playerAcceleration.y < 0 && player->coordinates.y > 0) ){

        player->coordinates.y += player->playerAcceleration.y;
    }
    else
        player->playerAcceleration.y = 0;

    if (player->coordinates.x + player->coordinates.w > 800){
        player->coordinates.x = 800 - player->coordinates.w;
    }
    else if (player->coordinates.x < 0) {
        player->coordinates.x = 0;
    }
    if (player->coordinates.y + player->coordinates.h > 600){
        player->coordinates.y = 600 - player->coordinates.h;
    }
    else if (player->coordinates.y < 0) {
        player->coordinates.y = 0;
    }

}

void setPlayerSize(Player* player){
    player->coordinates.h = player->RenderBox.h*3;
    player->coordinates.w =  player->RenderBox.w*3;
}

Player::state setPlayerState(Player player){

    if (player.playerAcceleration.x == 0 && player.playerAcceleration.y < 0){
        return Player::RUNNING_UP;
    }
    else if (player.playerAcceleration.x == 0 && player.playerAcceleration.y > 0){
        return Player::RUNNING_DOWN;
    }
    else if (player.playerAcceleration.x < 0 && player.playerAcceleration.y == 0){
        return Player::RUNNING_LEFT;
    }
    else if (player.playerAcceleration.x > 0 && player.playerAcceleration.y == 0){
        return Player::RUNNING_RIGHT;
    }
    else if (player.playerAcceleration.x < 0 && player.playerAcceleration.y < 0){
        return Player::RUNNING_LEFT_UP;
    }
    else if (player.playerAcceleration.x > 0 && player.playerAcceleration.y < 0){
        return Player::RUNNING_RIGHT_UP;
    }
    else if (player.playerAcceleration.x < 0 && player.playerAcceleration.y > 0){
        return Player::RUNNING_LEFT_DOWN;
    }
    else if (player.playerAcceleration.x > 0 && player.playerAcceleration.y > 0){
        return Player::RUNNING_RIGHT_DOWN;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(8)){
        return Player::STANDING_DOWN;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(9)){
        return Player::STANDING_UP;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(10)){
        return Player::STANDING_LEFT;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(11)){
        return Player::STANDING_RIGHT;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(12)){
        return Player::STANDING_LEFT_DOWN;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(13)){
        return Player::STANDING_RIGHT_DOWN;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(14)){
        return Player::STANDING_LEFT_UP;
    }
    else if ((player.playerAcceleration.x == 0 && player.playerAcceleration.y == 0) && player.actualstate == Player::state(15)){
        return Player::STANDING_RIGHT_UP;
    }
}


void initPlayerLocalization(Player* player){
    player->actualstate = Player::state(0);
    player->playerTextures.actualTexture = player->playerTextures.sDown;
    player->coordinates.x = 0;
    player->coordinates.y = 0;
    player->coordinates.h = 27*3;
    player->coordinates.w = 15*3;
    player->playerAcceleration.x = player->playerAcceleration.y = 0;
}
