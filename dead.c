#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

void Dead(){
    loadCine(2);
    //NF_HflipSprite(1, 0, false);
    for(int i = 0; i < 10; i++){
		skullDeath(i);
	}
    //NF_MoveSprite(1, 12, 256, 192);
    //NF_CreateSprite(1, 0, 0, 0, x, y);
    Mix_HaltChannel(-1);
	Mix_HaltMusic();
    cpos = 0;
    loadRoom(old, current);
    createImage("sprite/kirikouvide.png", 1, 480, 480);
    up = 0;
	down = 0;
	left = 0;
	right = 0;
    space = 0;
}