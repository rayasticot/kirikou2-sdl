#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

#define true 1
#define false 0


void Dungeon(){

	kirikouGunStart();
	alive = true;
	dingue = true;
	Mix_PlayMusic(music, -1);
	//NF_PlayRawSound(12, 127, 64, true, 0);
	up = 0;
    down = 0;
    left = 0;
    right = 0;
    space = 0;

    while(!close_requested){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT:
					close_requested = 1;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.scancode){
						case SDL_SCANCODE_SPACE:
							space = 1;
							break;
						case SDL_SCANCODE_UP:
							up = 1;
							break;
						case SDL_SCANCODE_DOWN:
							down = 1;
							break;
						case SDL_SCANCODE_RIGHT:
							right = 1;
							break;
						case SDL_SCANCODE_LEFT:
							left = 1;
							break;
						default:
							break;
					}
				break;
				case SDL_KEYUP:
					switch(event.key.keysym.scancode){
						case SDL_SCANCODE_SPACE:
							space = 0;
							break;
						case SDL_SCANCODE_UP:
							up = 0;
							break;
						case SDL_SCANCODE_DOWN:
							down = 0;
							break;
						case SDL_SCANCODE_RIGHT:
							right = 0;
							break;
						case SDL_SCANCODE_LEFT:
							left = 0;
							break;
						default:
							break;
					}
				break;
				default:
					break;
			}
		}
		kirikouGunUpdate();
		bulletUpdate();

		for(int i = 0; i < 10; i++){
			skullUpdate(i+5);
		}
    	Update();
		/*if(cpos == 1 && levelindex == 3){
			Boss();
			if(end == true){
				break;
			}
		}*/
		if(cpos == 4){
			dingue = false;
			cpos = 0;
			gameState += 1;
			for(int i = 0; i < 10; i++){
				skullDeath(i);
			}
			Mix_HaltChannel(-1);
			Mix_HaltMusic();

			if(levelindex == 2){
				loadCine(9);
			}
			loadRoom(old, current);
			createImage("sprite/kirikouvide.png", 1, 480, 480);
			break;
		}
		if(alive == false){
			dingue = false;
			if(levelindex != 3){
				Dead();
				break;
			}
			else{
				break;
			}
		}
	}
}