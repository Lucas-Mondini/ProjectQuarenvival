#include "quarenvivalIncludes.h"

using namespace std;


void GetSurfaceSuccessfull(const char* fileName){
    std::cout<<"Surface of fileName: \" "<<fileName <<" \" Loaded!\n";
}
void GetTextureSuccessfull(const char* fileName){
    std::cout <<"Texture : \" "<< fileName <<" \" Created!\n";
}

int TestLoadSurface (SDL_Surface* surface, const char* fileName){
    if (surface == NULL){
        GetError();
        return NULL;
    }
    else{
        GetSurfaceSuccessfull(fileName);
        return 1;
    }
}

int TestLoadTexture (SDL_Texture* texture, const char* fileName){
    if (texture == NULL){
        GetError();
        return NULL;
    }
    else{
        GetTextureSuccessfull(fileName);
        return 1;
    }
}

SDL_Texture* LoadImage(const char* fileName, SDL_Renderer* renderer){
    SDL_Surface* surface = SDL_LoadBMP(fileName);
    if (TestLoadSurface(surface, fileName) == NULL){
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (TestLoadTexture(texture, fileName) == NULL){
        return NULL;
    }

    SDL_FreeSurface(surface);

    return  texture;
}

pTextures LoadPlayerTextures (pTextures playerTextures, SDL_Renderer* renderer){
   playerTextures.sDown = LoadImage("../QuarenVival/assets/Standing/down.bmp", renderer);
   playerTextures.sUp = LoadImage("../QuarenVival/assets/Standing/up.bmp", renderer);
   playerTextures.sLeft = LoadImage("../QuarenVival/assets/Standing/left.bmp", renderer);
   playerTextures.sRight = LoadImage("../QuarenVival/assets/Standing/right.bmp", renderer);
   playerTextures.sLeftDown = LoadImage("../QuarenVival/assets/Standing/downleft.bmp", renderer);
   playerTextures.sRightDown = LoadImage("../QuarenVival/assets/Standing/downright.bmp", renderer);
   playerTextures.sLeftUp = LoadImage("../QuarenVival/assets/Standing/upleft.bmp", renderer);
   playerTextures.sRightUp = LoadImage("../QuarenVival/assets/Standing/upright.bmp", renderer);

   playerTextures.rDown = LoadImage("../QuarenVival/assets/Running/down.bmp", renderer);
   playerTextures.rUp = LoadImage("../QuarenVival/assets/Running/up.bmp", renderer);
   playerTextures.rLeft = LoadImage("../QuarenVival/assets/Running/left.bmp", renderer);
   playerTextures.rRight = LoadImage("../QuarenVival/assets/Running/right.bmp", renderer);
   playerTextures.rLeftDown = LoadImage("../QuarenVival/assets/Running/downleft.bmp", renderer);
   playerTextures.rRightDown = LoadImage("../QuarenVival/assets/Running/downright.bmp", renderer);
   playerTextures.rLeftUp = LoadImage("../QuarenVival/assets/Running/upleft.bmp", renderer);
   playerTextures.rRightUp = LoadImage("../QuarenVival/assets/Running/upright.bmp", renderer);

    return playerTextures;

};

SDL_Texture* setPlayerTexture(Player* player, int frame){
    if (player->actualstate == Player::STANDING_UP){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sUp;
    }
    else if (player->actualstate == Player::STANDING_DOWN){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sDown;
    }
    else if (player->actualstate == Player::STANDING_LEFT){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sLeft;
    }
    else if (player->actualstate == Player::STANDING_RIGHT){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sRight;
    }
    else if (player->actualstate == Player::STANDING_LEFT_UP){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sLeftUp;
    }
    else if (player->actualstate == Player::STANDING_RIGHT_UP){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sRightUp;
    }
    else if (player->actualstate == Player::STANDING_LEFT_DOWN){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sLeftDown;
    }
    else if (player->actualstate == Player::STANDING_RIGHT_DOWN){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sRightDown;
    }


    else if (player->actualstate == Player::RUNNING_UP){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rUp;
    }
    else if (player->actualstate == Player::RUNNING_DOWN){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rDown;
    }
    else if (player->actualstate == Player::RUNNING_LEFT){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rLeft;
    }
    else if (player->actualstate == Player::RUNNING_RIGHT){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rRight;
    }
    else if (player->actualstate == Player::RUNNING_LEFT_UP){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rLeftUp;
    }
    else if (player->actualstate == Player::RUNNING_RIGHT_UP){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rRightUp;
    }
    else if (player->actualstate == Player::RUNNING_LEFT_DOWN){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rLeftDown;
    }
    else if (player->actualstate == Player::RUNNING_RIGHT_DOWN){
        setPlayerRenderBox(player, frame);
        return player->playerTextures.rRightDown;
    }
    else
    {
        setPlayerRenderBox(player, frame);
        return player->playerTextures.sDown;
    }
}
void setPlayerRenderBox(Player* player, int frame){
    if (player->actualstate == Player::STANDING_DOWN || player->actualstate == Player::STANDING_UP)
    {
        player->RenderBox.x=0;
        player->RenderBox.y=0;
        player->RenderBox.w=15;
        player->RenderBox.h=27;
    }

    else if(player->actualstate == Player::STANDING_LEFT || player->actualstate == Player::STANDING_RIGHT)
    {
        player->RenderBox.x=0;
        player->RenderBox.y=0;
        player->RenderBox.w=8;
        player->RenderBox.h=27;
    }

    else if (player->actualstate == Player::STANDING_LEFT_UP || player->actualstate == Player::STANDING_RIGHT_UP || player->actualstate == Player::STANDING_LEFT_DOWN || player->actualstate == Player::STANDING_RIGHT_DOWN)
    {
        player->RenderBox.x=0;
        player->RenderBox.y=0;
        player->RenderBox.w=12;
        player->RenderBox.h=29;
    }
    else if (player->actualstate == Player::RUNNING_UP || player->actualstate == Player::RUNNING_DOWN){
        player->RenderBox.x = (frame % 4) * 15;
        player->RenderBox.y = 0;
        player->RenderBox.w = 15;
        player->RenderBox.h = 27;
    }
    else if (player->actualstate == Player::RUNNING_LEFT || player->actualstate == Player::RUNNING_RIGHT){
        player->RenderBox.x = (frame % 4) * 11;
        player->RenderBox.y = 0;
        player->RenderBox.w = 11;
        player->RenderBox.h = 27;
    }
    else if (player->actualstate == Player::RUNNING_LEFT_UP || player->actualstate == Player::RUNNING_LEFT_DOWN || player->actualstate == Player::RUNNING_RIGHT_UP || player->actualstate == Player::RUNNING_RIGHT_DOWN){
        player->RenderBox.x = (frame % 4) * 14;
        player->RenderBox.y = 0;
        player->RenderBox.w = 14;
        player->RenderBox.h = 27;
    }
    else{
        player->RenderBox.x=0;
        player->RenderBox.y=0;
        player->RenderBox.w=15;
        player->RenderBox.h=27;
    }

}

void DestroyPlayerTextures (Player* player){
    SDL_DestroyTexture(player->playerTextures.actualTexture);
    SDL_DestroyTexture(player->playerTextures.sDown);
    SDL_DestroyTexture(player->playerTextures.sUp);
    SDL_DestroyTexture(player->playerTextures.sLeft);
    SDL_DestroyTexture(player->playerTextures.sRight);
    SDL_DestroyTexture(player->playerTextures.sLeftUp);
    SDL_DestroyTexture(player->playerTextures.sRightUp);
    SDL_DestroyTexture(player->playerTextures.sLeftDown);
    SDL_DestroyTexture(player->playerTextures.sRightDown);

    SDL_DestroyTexture(player->playerTextures.rDown);
    SDL_DestroyTexture(player->playerTextures.rUp);
    SDL_DestroyTexture(player->playerTextures.rLeft);
    SDL_DestroyTexture(player->playerTextures.rRight);
    SDL_DestroyTexture(player->playerTextures.rLeftUp);
    SDL_DestroyTexture(player->playerTextures.rRightUp);
    SDL_DestroyTexture(player->playerTextures.rLeftDown);
    SDL_DestroyTexture(player->playerTextures.rRightDown);


}
