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
    //NEXT STEP PUT THE NEXT DAY CONDITIONS HERE
    //NEXT STEP PUT THE NEXT DAY CONDITIONS HERE
    //NEXT STEP PUT THE NEXT DAY CONDITIONS HERE
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
SDL_Texture* nextDay(dTextures day, int i){
    if (i == 2){
        return day.iDay_2;
    }
    if (i == 3){
        return day.iDay_3;
    }
    if (i == 4){
        return day.iDay_4;
    }
    if (i == 5){
        return day.iDay_5;
    }
    if (i == 6){
        return day.iDay_6;
    }
    if (i == 7){
        return day.iDay_7;
    }
}

SDL_Rect SetEkeyLocation (tImages* image, string Location){

    if(Location == "Refrigerator"){
        image->location.x = 200;
        image->location.y = 70;
        image->location.h = 50;
        image->location.w = 50;
    }
    if(Location == "Couch"){
        image->location.x = 325;
        image->location.y = 70;
        image->location.h = 50;
        image->location.w = 50;
    }
    if(Location == "Bed"){
        image->location.x = 600;
        image->location.y = 70;
        image->location.h = 50;
        image->location.w = 50;
    }
    if(Location == "Door"){
        image->location.x = 550;
        image->location.y = 400;
        image->location.h = 50;
        image->location.w = 50;
    }

    return image->location;
}

void setPlayerLocation (Player* player){
    bool CanMove = true;
    for (int x = 245 ; x > 100 ; x--){
        for (int y = 100; y > 70; y--){
            if (player->coordinates.x < x && player->coordinates.y < y){
                player->playerAcceleration.x = 0;
                player->playerAcceleration.y = 0;
                player->coordinates.x += 1;
                player->coordinates.y += 1;
                if(player->coordinates.x <= 150 )
                player->actualstate = Player::RUNNING_UP;
                else if(player->coordinates.x <= 200 && player->coordinates.x > 150)
                player->actualstate = Player::RUNNING_LEFT_UP;
                else if (player->coordinates.x < 245 && player->coordinates.x > 230)
                player->actualstate = Player::RUNNING_LEFT;

                CanMove = false;
            }
        }
    }



    if((player->playerAcceleration.x > 0 && player->coordinates.x < 800 - player->coordinates.w ) || (player->playerAcceleration.x < 0 && player->coordinates.x > 0) && CanMove ){

        player->coordinates.x += player->playerAcceleration.x;
    }
    else
        player->playerAcceleration.x=0;

    if( (player->playerAcceleration.y > 0 && player->coordinates.y < 600 - player->coordinates.h) || (player->playerAcceleration.y < 0 && player->coordinates.y > 0 && CanMove) ){

        player->coordinates.y += player->playerAcceleration.y;
    }
    else
        player->playerAcceleration.y = 0;

    if (player->coordinates.x + player->coordinates.w > 700){
        player->coordinates.x = 700 - player->coordinates.w;
    }
    else if (player->coordinates.x < 110) {
        player->coordinates.x = 110;
    }
    if (player->coordinates.y + player->coordinates.h > 505){
        player->coordinates.y = 505 - player->coordinates.h;
    }
    else if (player->coordinates.y < 70) {
        player->coordinates.y = 70;
    }
    CanMove = true;

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
