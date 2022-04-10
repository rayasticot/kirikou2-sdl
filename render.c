#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

SDL_Texture* tex[30];
uint8_t texindex[30];
SDL_Rect rect[30];
SDL_Window* win;
Uint32 render_flags;
SDL_Renderer* rend;

void createImage(char* link, uint8_t id, int16_t x, int16_t y){
    SDL_Surface* surface = IMG_Load(link);
    if(!surface){
        printf("error: %s", SDL_GetError());
    }
    tex[id] = SDL_CreateTextureFromSurface(rend, surface);
    if(!tex[id]){
        printf("error: %s", SDL_GetError());
    }
    SDL_FreeSurface(surface);
    texindex[id] = 1;
    SDL_QueryTexture(tex[id], NULL, NULL, &rect[id].w, &rect[id].h);
    rect[id].x = x;
    rect[id].y = y;
}

void destroyImage(uint8_t id){
    SDL_DestroyTexture(tex[id]);
    texindex[id] = 0;
    rect[id].x = -128;
    rect[id].y = -128; 
}

void Update(){
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, tex[0], NULL, &rect[0]);
    for(uint8_t i = 2; i < 30; i++){
        if(texindex[i] == 0){
            continue;
        }
        SDL_RenderCopy(rend, tex[i], NULL, &rect[i]);
    }
    SDL_RenderCopy(rend, tex[1], NULL, &rect[1]);
    SDL_RenderPresent(rend);
}