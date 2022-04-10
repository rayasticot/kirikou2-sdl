#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

void overWorld(){

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
		kirikouUpdate();
		Update();
		//uiUpdate(); Cassé
		if(current.obj_x[npcpoint] != 0){
			npcUpdate(npcpoint, 2, 2);
		}
		if(current.obj_x[cavepoint] != 0){
			caveUpdate(cavepoint, current, dung[levelindex][0]);
		}
		if(current.obj_x[bolepoint] != 0){
			boleUpdate(bolepoint, current);
		}
		if(current.obj_x[boatpoint] != 0){
			boatUpdate(boatpoint);
		}
		/*if(end == true){
			break;
		}*/
	}
}