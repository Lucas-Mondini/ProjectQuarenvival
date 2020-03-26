#ifndef QUARENVIVALFUNCTIONS_H
#define QUARENVIVALFUNCTIONS_H
#include "quarenvivalIncludes.h"
#include "quarenvivalStructures.h"

void CallError(bool &running);
void GetError();




void keyListener(SDL_Event event, Player* player);
void eventListener(SDL_Event event, bool running, Player* player);

void initPlayerLocalization(Player* player);

void setPlayerRenderBox(Player* player, int frame);
void setPlayerSize(Player* player);
void setPlayerLocation (Player* player);

Player::state setPlayerState(Player player);





#endif // QUARENVIVALFUNCTIONS_H
