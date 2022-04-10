#ifndef VARS_H
#define VARS_H
SDL_Texture* tex[30];
Mix_Chunk *sound[10];
Mix_Music *music;
uint8_t texindex[30];
SDL_Rect rect[30];
SDL_Window* win;
Uint32 render_flags;
SDL_Renderer* rend;

int npcpoint;
int cavepoint;
int skullpoint;
int bolepoint;
int boatpoint;
int skullnum;
int gameState;
int levelindex;
int cpos;
int opos;
_Bool alive;
_Bool dingue;
_Bool end;
uint8_t space, up, down, right, left;
int skullx[16];
int skully[16];
int dir[16];
_Bool skullLive[16];
_Bool bul;
_Bool lock;

struct map current;
struct map old;

uint8_t close_requested;

struct map benin[3][3];
struct map spain[3][3];
struct map franc[3][3];
struct map retour[3][3];
struct map dung[4][4];
struct spritelist list[5];
struct cinematic cinema[12];
#endif