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


void eventListener(SDL_Event event, bool running)
{
    if(event.type == SDL_QUIT)
        running = false;
//    switch(event.type)
//    {
//        case SDL_QUIT:
//            running = false;
//            break;
//    }
}


void keyListener(Player* player, const Uint8* keyState)
{

        keyState = SDL_GetKeyboardState(NULL);
            if(keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D]){
                cout <<"direita\n";
                if(player->playerAcceleration.x < 6)
                    player->playerAcceleration.x+= 3;
                else if (player->playerAcceleration.x < 0){
                    player->playerAcceleration.x += 9;
                }
            }
            if(keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A]){
                cout <<"esquerda\n";
                if(player->playerAcceleration.x > -6)
                    player->playerAcceleration.x-= 3;
                else if (player->playerAcceleration.x > 0){
                    player->playerAcceleration.x -= 9;
                }
            }
            if(keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W]){
                cout <<"cima\n";
                if(player->playerAcceleration.y > - 6)
                    player->playerAcceleration.y-= 3;
                else if (player->playerAcceleration.y > 0){
                    player->playerAcceleration.y -= 9;
                }
            }
            if(keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S]){
                cout <<"baixo\n";
                if(player->playerAcceleration.y < 6)
                    player->playerAcceleration.y+= 3;
                else if (player->playerAcceleration.y < 0){
                    player->playerAcceleration.y += 9;
                }
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
    else if (player->coordinates.y < 100) {
        player->coordinates.y = 100;
    }

}

void setPlayerSize(Player* player){
    player->coordinates.h = player->RenderBox.h*5;
    player->coordinates.w =  player->RenderBox.w*5;
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
    player->coordinates.x = 400;
    player->coordinates.y = 300;
    player->coordinates.h = 27*5;
    player->coordinates.w = 15*5;
    player->playerAcceleration.x = player->playerAcceleration.y = 0;
    player->RenderBox.h = 27;
    player->RenderBox.w = 15;
}
