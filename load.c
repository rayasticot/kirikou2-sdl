#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

void setMinus(){
	npcpoint = -128;
	cavepoint = -128;
	bolepoint = -128;
	boatpoint = -128;
}
void loadRoom(struct map carte, struct map old){
	skullnum = 0;
	if(dingue == 0){
		Mix_HaltChannel(-1);
	}
	for(int i = 0; i <= 10; i++){
		if(old.object[i] > 0){
            destroyImage(i+5);
		}
		else{
			break;
		}
	}
	for(int i = 0; i <= 10; i++){
		if(carte.object[i] > 0){
			switch(carte.object[i]){
				case 1:
                    createImage(list[levelindex].link[0], i+5, carte.obj_x[i]*4, carte.obj_y[i]*4);
					setMinus();
					break;
				case 2:
					npcStart(i+5, carte.obj_x[i]*4, carte.obj_y[i]*4, carte.npcsprite);
					npcpoint = i;
					break;
				case 3:
					caveStart(i+5, carte.obj_x[i]*4, carte.obj_y[i]*4);
					cavepoint = i;
					break;
				case 4:
					skullStart(i+5, current, carte.obj_x[i]*4, carte.obj_y[i]*4, 3);
					if(skullpoint == 0){
						skullpoint = i;
					}
					skullnum += 1;
					break;
				case 5:
					boleStart(i, carte, carte.obj_x[i]*4, carte.obj_y[i]*4);
					bolepoint = i;
					break;
				case 6:
					createImage("sprite/titanic.png", i+5, carte.obj_x[i]*4, carte.obj_y[i]*4);
					boatpoint = i;
					break;
				case 7:
                    createImage(list[levelindex].link[7], i+5, carte.obj_x[i]*4, carte.obj_y[i]*4);
					setMinus();
					break;
				case 8:
                    createImage(list[levelindex].link[8], i+5, carte.obj_x[i]*4, carte.obj_y[i]*4);
					setMinus();
					break;
				case 9:
                    createImage(list[levelindex].link[9], i+5, carte.obj_x[i]*4, carte.obj_y[i]*4);
					setMinus();
					break;
			}
		}
		else{
			break;
		}
	}
	for(int i = 0; i < 5; i++){
		if(carte.sound[i] != NULL){
            sound[i] = Mix_LoadWAV(carte.sound[i]);
		}
	}
	if(carte.background != NULL){
        createImage(carte.background, 0, 0, 0);
	}
	current = carte;
}
void loadCine(uint8_t id){
	uint16_t temporarx = rect[1].x;
	rect[1].x = 2048;
    createImage(cinema[id].bg[0], 28, 0, 0);
    sound[0] = Mix_LoadWAV(cinema[id].sound[0]);
    Mix_PlayChannel(-1, sound[0], 0);
    for(int i = 1; i < 8; i++){
		if(cinema[id].sound[i] != NULL){
            sound[i] = Mix_LoadWAV(cinema[id].sound[i]);
		}
	}
    while(!close_requested){
        _Bool enter = 0;
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    close_requested = 1;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.scancode == SDL_SCANCODE_RETURN){
                        enter = 1;
                    }
                    break;
            }
        }
        Update();
        if(enter == 1){
            break;
        }
    }
    for(int i = 1; i < 8; i++){
		if(cinema[id].sound[i] == NULL){
			Mix_HaltChannel(-1);
			break;
		}
		if(cinema[id].sound[i] != 0){
            Mix_HaltChannel(-1);
            Mix_PlayChannel(-1, sound[i], 0);
		}
		if(cinema[id].bg[i] != 0){
            createImage(cinema[id].bg[i], 28, 0, 0);
		}
		while(!close_requested){
            _Bool enter = 0;
            SDL_Event event;
            while (SDL_PollEvent(&event)){
                switch (event.type){
                    case SDL_QUIT:
                        close_requested = 1;
                        break;
                    case SDL_KEYDOWN:
                        if(event.key.keysym.scancode == SDL_SCANCODE_RETURN){
                            enter = 1;
                        }
                        break;
                }
            }
            Update();
            if(enter == 1){
                break;
            }
        }
	}
	rect[1].x = temporarx;
	destroyImage(28);
}