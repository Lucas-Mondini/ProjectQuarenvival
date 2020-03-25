#ifndef QUARENVIVALTEXTUREMANAGER_H
#define QUARENVIVALTEXTUREMANAGER_H
#include "quarenvivalIncludes.h"

int TestLoadSurface (SDL_Surface* surface, const char* fileName);
int TestLoadTexture (SDL_Texture* texture, const char* fileName);


void GetSurfaceSuccessfull(const char* fileName);
void GetTextureSuccessfull(const char* fileName);

pTextures LoadPlayerTextures (pTextures playerTextures,SDL_Renderer* renderer);
void DestroyPlayerTextures (Player* player);

SDL_Texture* LoadImage(const char* fileName, SDL_Renderer* renderer);

#endif // QUARENVIVALTEXTUREMANAGER_H
