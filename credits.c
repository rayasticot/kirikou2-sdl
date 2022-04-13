#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

uint16_t timmy = 0;
uint16_t jimmy = 0;
uint8_t james = 0;
char paul[22]; 


void Credits(){
    destroyImage(0);
    destroyImage(1);
    destroyImage(2);
    destroyImage(20);

	/*NF_LoadTiledBg("bg/credits/cre0", "cre0", 256, 256);
	NF_LoadTiledBg("bg/credits/cre1", "cre1", 256, 256);
	NF_LoadTiledBg("bg/credits/cre2", "cre2", 256, 256);
	NF_LoadTiledBg("bg/credits/cre3", "cre3", 256, 256);
	NF_LoadTiledBg("bg/credits/cre4", "cre4", 256, 256);
	NF_LoadTiledBg("bg/credits/cre5", "cre5", 256, 256);
	NF_LoadTiledBg("bg/credits/cre6", "cre6", 256, 256);
	NF_LoadTiledBg("bg/credits/cre7", "cre7", 256, 256);
	NF_LoadTiledBg("bg/credits/cre8", "cre8", 256, 256);*/
    
    Mix_HaltChannel(-1);
    sound[0] = Mix_LoadWAV("sound/charte0.wav");
    sound[1] = Mix_LoadWAV("sound/charte1.wav");

    createImage("bg/credits/cre0.png", 29, 0, 0);
    Mix_PlayChannel(-1, sound[0], 0);

    while(!close_requested){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                close_requested = 1;
            }
        }
        Update();
        if(timmy == 1110){
            Mix_HaltChannel(-1);
            Mix_PlayChannel(-1, sound[1], 0);
        }
        if(jimmy == 270){
            james += 1;
            if(james == 9){
                break;
            }
            sprintf(paul, "bg/credits/cre%u.png", james);
            createImage(paul, 29, 0, 0);
            jimmy = 0;
        }
        timmy++;
        jimmy++;
    }
}
