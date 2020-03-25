#define SDL_MAIN_HANDLED
#include <iostream>
#include "QuarenvivalFunctions.h"
#include <SDL2/SDL.h>

using namespace std;

int height = 800;
int weight = 600;

int main()
{
    bool running;
    //initializes the SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        CallError(running);
    else
    {
        running = true;
        cout <<"SDL initialized!" <<endl;
    }


    SDL_Window* window = SDL_CreateWindow("Quarenvival",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          height, weight, 0);
    if (window == NULL)
        CallError(running);
    else
    {
        running = true;
        cout <<"Window created!" <<endl;

    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        CallError(running);
    else{
        running = true;
        cout <<"Renderer created!" <<endl;
    }

    //Create Player
       Player player;
    //Create Player


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        player.playerTextures = LoadPlayerTextures(player.playerTextures, renderer);

        initPlayerLocalization(&player);




    int quadro = 0;
    //gameloop begins
    while (running){
        //process enters

        SDL_Event event;
        while(SDL_PollEvent(&event)){//get all events
            eventListener(event, &running, &player);
        }

        SDL_RenderClear(renderer);

        setPlayerRenderBox(&player);
        setPlayerSize(&player);

        SDL_RenderCopy(renderer, player.playerTextures.actualTexture, &player.RenderBox, &player.coordinates);



        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
        quadro++;
    }
    //gameloop ends


    SDL_DestroyRenderer(renderer);
    DestroyPlayerTextures(&player);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
