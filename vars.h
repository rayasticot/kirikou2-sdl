#ifndef VARS_H
#define VARS_H
extern SDL_Texture* tex[30];
extern Mix_Chunk *sound[10];
extern Mix_Music *music;
extern uint8_t texindex[30];
extern SDL_Rect rect[30];
extern SDL_Window* win;
extern Uint32 render_flags;
extern SDL_Renderer* rend;

extern int npcpoint;
extern int cavepoint;
extern int skullpoint;
extern int bolepoint;
extern int boatpoint;
extern int skullnum;
extern int gameState;
extern int levelindex;
extern int cpos;
extern int opos;
extern _Bool alive;
extern _Bool dingue;
extern _Bool end;
extern uint8_t space, up, down, right, left;
extern int skullx[16];
extern int skully[16];
extern int dir[16];
extern _Bool skullLive[16];
extern _Bool bul;
extern _Bool lock;

extern struct map current;
extern struct map old;

extern uint8_t close_requested;

extern struct map benin[3][3];
extern struct map spain[3][3];
extern struct map franc[3][3];
extern struct map retour[3][3];
extern struct map dung[4][4];
extern struct spritelist list[5];
extern struct cinematic cinema[12];
#endif