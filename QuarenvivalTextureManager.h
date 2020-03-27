#ifndef QUARENVIVALTEXTUREMANAGER_H
#define QUARENVIVALTEXTUREMANAGER_H
#include "quarenvivalIncludes.h"

int TestLoadSurface (SDL_Surface* surface, const char* fileName);
int TestLoadTexture (SDL_Texture* texture, const char* fileName);


void GetSurfaceSuccessfull(const char* fileName);
void GetTextureSuccessfull(const char* fileName);

Prop LoadProp(Prop prop, SDL_Renderer* renderer, const char* fileName);
void DestroyProp(Prop* prop);

dTextures LoadDayTextures (dTextures dayTextures, SDL_Renderer* renderer);

Background LoadBackground (Background background, const char* fileName, SDL_Renderer* renderer);

tImages LoadImageTextureFillRect (tImages, const char* fileName, SDL_Renderer* renderer);

pTextures LoadPlayerTextures (pTextures playerTextures,SDL_Renderer* renderer);
void DestroyPlayerTextures (Player* player);

SDL_Texture* setPlayerTexture(Player* player, int frame);

SDL_Texture* LoadImage(const char* fileName, SDL_Renderer* renderer);

#endif // QUARENVIVALTEXTUREMANAGER_H
