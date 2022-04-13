#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "include.h"

void Title(){
    _Bool enter = 0;
    createImage("bg/kirikou2.png", 0, 0, 0);
    while(!close_requested){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    close_requested = 1;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.scancode == SDL_SCANCODE_SPACE){
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