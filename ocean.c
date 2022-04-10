#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

void Ocean(struct map next){
    Mix_HaltChannel(-1);
	for(int i = 0; i <= 10; i++){
		destroyImage(i+5);
	}
	destroyImage(1);

	createImage("bg/sea.png", 0, 0 ,0);
	createImage("sprite/titanic.png", 4, 1024, 128*4);
    while(rect[4].x > -128){
		rect[4].x -= 8;
        Update();
    }
	//unloadLevelSprite();
    //switchSprite(levelindex);
	//NF_CreateTiledBg(0, 3, "bg/green");
	loadCine(5+levelindex);
    loadRoom(next, current);
	createImage("sprite/kirikouvide.png", 1, 104*4, 144*4);
	up = 0;
	down = 0;
	left = 0;
	right = 0;
    space = 0;
	//topSwitch();
}