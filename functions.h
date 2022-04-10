#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void createImage(char* link, uint8_t id, int16_t x, int16_t y);
void destroyImage(uint8_t id);
void Update();
void Title();
void loadCine(uint8_t id);
void movementCheckFin();
void kirikouStart(int px, int py);
void kirikouUpdate();
void kirikouGunStart();
void kirikouGunUpdate();
void movementCheckFin();
void bulletUpdate();
_Bool checkCollision(int x1, int y1, int sx1, int sy1, int x2, int y2, int sx2, int sy2);
void setList();
void npcStart(int i, int x, int y, int sprite);
void npcUpdate(int i, int posx, int posy);
void overWorld();
void loadRoom(struct map carte, struct map old);
void boleStart(int i, struct map carte, int px, int py);
void boleUpdate(int i, struct map carte);
void skullDeath(int i);
void skullStart(int i, struct map carte, int px, int py, int sprite);
void skullUpdate(int i);
void Dead();
void caveStart(int i, int x, int y);
void caveUpdate(int i, struct map curr, struct map neww);
void Dungeon();
void Ocean(struct map next);
void boatUpdate(int i);
#endif