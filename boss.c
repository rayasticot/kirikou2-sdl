#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

#define u8 uint8_t
#define u16 uint16_t
#define s16 int16_t
#define bool _Bool
#define false 0
#define true 1

u8 karaba_h = 0;/**/
u8 karaba_life = 10;
u16 timer = 0;
u8 invtime = 0;
s16 tempx = 224;/**/
bool karaba_dir = false;
bool karaba_inv = false;

void Karaba(){
    if(rect[20].y == 0){
        karaba_dir = false;
    }
    if(rect[20].y == 640){
        karaba_dir = true;
    }
    if(karaba_dir == true){
        rect[20].y -= 8;
    }
    else{
        rect[20].y += 8;
    }
    //NF_MoveSprite(1, 19, tempx, karaba_h);
    if(checkCollision(rect[1].x, rect[1].y, 64, 128, rect[20].x, rect[20].y, 128, 256) == true){
        alive = false;
    }
    if(timer == 240){
        Mix_PlayChannel(-1, sound[1], 0);
    }
    if(timer > 300){
        rect[20].x -= 16;
        if(rect[20].x < rect[1].x-64){
            rect[20].x = 896;
            timer = 0;
        }
    }
    if(checkCollision(rect[2].x, rect[2].y, 32, 32, rect[20].x, rect[20].y, 128, 256) == true){
        bul = false;
        lock = false;
        rect[2].x = 1024;
        if(karaba_inv == false){
            karaba_life--;
	        Mix_PlayChannel(-1, sound[0], 0);
            karaba_inv = true;
            int16_t tempxskulx, tempxskuly;
            tempxskulx = rect[20].x;
            tempxskuly = rect[20].y;
            destroyImage(20);
            createImage("sprite/re/karabah.png", 20, tempxskulx, tempxskuly);
            //NF_VramSpritePal(1, 3, 5);
            invtime = 0;

            if(karaba_life == 0){
                destroyImage(20);
                end = true;
            }
        }
    }
    if(karaba_inv == true){
        invtime++;
        if(invtime == 128){
            int16_t tempxskulx, tempxskuly;
            tempxskulx = rect[20].x;
            tempxskuly = rect[20].y;
            destroyImage(20);
            createImage("sprite/re/karaba.png", 20, tempxskulx, tempxskuly);
	        //NF_VramSpritePal(1, 5, 5);
            karaba_inv = false;
            invtime = 0;
        }
    }
    timer++;
}

void Boss(){
    up = 0;
    down = 0;
    left = 0;
    right = 0;
    space = 0;

    createImage("bg/level4.png", 0, 0, 0);
    createImage("sprite/re/karaba.png", 20, 896, 256);

    Mix_HaltChannel(-1);

    loadCine(10);

    sound[0] = Mix_LoadWAV("sound/kara2.wav");
    sound[1] = Mix_LoadWAV("sound/kara3.wav");
    music = Mix_LoadMUS("sound/zzz.wav");

    Mix_PlayMusic(music, -1);

    rect[20].y = 0;
    karaba_h = 0;
    karaba_life = 2;
    timer = 0;
    tempx = 896;
    karaba_dir = false;

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
        Update();
        Karaba();
        if(end == true){
            Mix_HaltChannel(-1);
            Mix_HaltMusic();
            loadCine(11);
            destroyImage(1);
            break;
        }
        if(alive == false){
            Mix_HaltChannel(-1);
            destroyImage(20);
            Dead();
			break;
		}
    }
}