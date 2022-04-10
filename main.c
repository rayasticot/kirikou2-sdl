#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "struct.h"

SDL_Texture* tex[30];
Mix_Chunk *sound[10];
Mix_Music *music;
uint8_t texindex[30] = {0};
SDL_Rect rect[30];
SDL_Window* win;
Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
SDL_Renderer* rend;
uint8_t close_requested = 0;

int npcpoint;
int cavepoint;
int skullpoint;
int bolepoint;
int boatpoint;
int skullnum;
int gameState = 0;
int levelindex = 0;
int cpos = 0;
int opos = 0;
int skullx[16];
int skully[16];
int dir[16];
_Bool skullLive[16];
_Bool alive = 1;
_Bool dingue = 0;
_Bool end = 0;
_Bool bouf = 0;
uint8_t space, up, down, right, left;

struct map benin[3][3];
struct map spain[3][3];
struct map franc[3][3];
struct map retour[3][3];
struct map dung[4][4];
struct spritelist list[5];
struct cinematic cinema[12];

struct map current;
struct map old;

#include "map.h"
#include "functions.h"
#include "kirikou.h"
#include "npc.h"
#include "spritelist.h"
#include "bole.h"
#include "cave.h"
#include "skull.h"
#include "boat.h"

_Bool checkCollision(int x1, int y1, int sx1, int sy1, int x2, int y2, int sx2, int sy2){
	if(x1+sx1 > x2 && x1 < x2+sx2){
		if(y1+sy1 > y2 && y1 < y2+sy2){
			return 1;
		}
	}
	return 0;
}

int main(){
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    win = SDL_CreateWindow("kirikou2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
    rend = SDL_CreateRenderer(win, -1, render_flags);

    setList();
    setLevel();
	setCine();

    Title();

    loadCine(0);
    kirikouStart(480, 480);
	loadRoom(benin[1][1], benin[1][1]);
    overWorld();
    Credits();
    
    SDL_Event event;

    while(!close_requested){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                close_requested = 1;
            }
        }
        Update();
    }
    for(uint8_t i = 0; i < 30; i++){
        if(texindex[i] == 0){
            continue;
        }
        destroyImage(0);
    }
    Mix_Quit();
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}