#define SDL_MAIN_HANDLED
#include <iostream>
#include "QuarenvivalFunctions.h"
#include <SDL2/SDL.h>

using namespace std;

int height = 800;
int weight = 600;

int main()
{
    const Uint8* keyState;
    int time = 6;
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
    //Create Props
       Prop BlueCouch;
       BlueCouch.id = BLUE_COUCH;
       BlueCouch = LoadProp(BlueCouch, renderer, "../QuarenVival/assets/Props/BlueCouch.bmp");

       Prop Refriferator;
       Refriferator.id = REFRIGERATOR;
       Refriferator = LoadProp(Refriferator, renderer, "../QuarenVival/assets/Props/refrigerator.bmp");

       Prop Bed;
       Bed.id = BED;
       Bed = LoadProp(Bed, renderer, "../QuarenVival/assets/Props/bed.bmp");
    //Create Props

    //Create Text
    dTextures dayTextures = LoadDayTextures(dayTextures, renderer);
    tImages Ekey = LoadImageTextureFillRect(Ekey, "../QuarenVival/assets/Texts/Ekey.bmp", renderer);

    //Create Text

    //Create Background
    Background background = LoadBackground(background, "../QuarenVival/assets/background/Background.bmp", renderer);
    //Create Background


    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 0);

        player.playerTextures = LoadPlayerTextures(player.playerTextures, renderer);

        initPlayerLocalization(&player);
        player.nextDay = false;

    dayTextures.Actual_Day = dayTextures.iDay_1;
    int actualday = 1;
    int frame = 0;
    int animframe = 0;
    //gameloop begins
    while (running){
        //process enters

        SDL_Event event;
        while(SDL_PollEvent(&event)){//get all events
            eventListener(event, &running);
        }
        keyListener(&player, keyState);

        SDL_RenderClear(renderer);

        player.actualstate = setPlayerState(player);
        setPlayerSize(&player);
        setPlayerLocation (&player);

        player.playerTextures.actualTexture = setPlayerTexture(&player, animframe);

        SDL_RenderCopy(renderer, background.texture, &background.source, &background.location);
        SDL_RenderCopy(renderer, BlueCouch.propTexture, &BlueCouch.propRenderBox, &BlueCouch.propCoordinate);
        SDL_RenderCopy(renderer, Refriferator.propTexture, &Refriferator.propRenderBox, &Refriferator.propCoordinate);
        SDL_RenderCopy(renderer, Bed.propTexture, &Bed.propRenderBox, &Bed.propCoordinate);
        SDL_RenderCopy(renderer, player.playerTextures.actualTexture, &player.RenderBox, &player.coordinates);
        SDL_RenderCopy(renderer, dayTextures.Actual_Day, &dayTextures.dSource, &dayTextures.dDestiny);

        if(player.coordinates.x < 230 && player.coordinates.y < 200){
            Ekey.location = SetEkeyLocation(&Ekey, "Refrigerator");
            SDL_RenderCopy(renderer, Ekey.texture, &Ekey.source, &Ekey.location);
        }
        if(player.coordinates.x > 230 && player.coordinates.x < 400 && player.coordinates.y < 200){
            Ekey.location = SetEkeyLocation(&Ekey, "Couch");
            SDL_RenderCopy(renderer, Ekey.texture, &Ekey.source, &Ekey.location);
        }
        if( player.coordinates.x > 500 && player.coordinates.y < 200){
            Ekey.location = SetEkeyLocation(&Ekey, "Bed");
            dayTextures.Actual_Day = nextDay(dayTextures, actualday++);
            SDL_RenderCopy(renderer, Ekey.texture, &Ekey.source, &Ekey.location);
        }
        if( player.coordinates.x > 400 && player.coordinates.x < 500 && player.coordinates.y > 300){
            Ekey.location = SetEkeyLocation(&Ekey, "Door");
            SDL_RenderCopy(renderer, Ekey.texture, &Ekey.source, &Ekey.location);
        }


        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
        frame++;
        if (frame % 6 == 0){
            animframe ++;
            player.playerAcceleration.x = player.playerAcceleration.y = 0;
        }

        if(frame > 60)
            animframe = frame = 0;
    }
    //gameloop ends


    SDL_DestroyRenderer(renderer);
    DestroyPlayerTextures(&player);
    DestroyProp(&BlueCouch);
    DestroyProp(&Refriferator);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
