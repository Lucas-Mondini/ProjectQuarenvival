#ifndef QUARENVIVALFUNCTIONS_H
#define QUARENVIVALFUNCTIONS_H
#include "quarenvivalIncludes.h"
#include "quarenvivalStructures.h"
using namespace std;

void CallError(bool &running);
void GetError();




void keyListener(Player* player, const Uint8* keyState);
void eventListener(SDL_Event event, bool running);

void initPlayerLocalization(Player* player);

void setPlayerRenderBox(Player* player, int frame);
void setPlayerSize(Player* player);
void setPlayerLocation (Player* player);
SDL_Rect SetEkeyLocation (tImages* image, string Location);
SDL_Texture* nextDay(dTextures day, int i);


Player::state setPlayerState(Player player);





#endif // QUARENVIVALFUNCTIONS_H
