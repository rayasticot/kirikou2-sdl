#ifndef CAVE_H
#define CAVE_H
void caveStart(int i, int x, int y){
    createImage(list[levelindex].link[5], i, x, y);
}
void caveUpdate(int i, struct map curr, struct map neww){
    if(checkCollision(rect[1].x, rect[1].y, 64, 128, curr.obj_x[i]*4, curr.obj_y[i]*4, 128, 128) == true){
        if(gameState == levelindex){
            old = current;
            loadRoom(neww, curr);
            rect[1].x = 0;
            kirikouUpdate();
            if(gameState == 0){
                loadCine(1);
            }
            music = Mix_LoadMUS("sound/certe.wav");
            up = 0;
            down = 0;
            left = 0;
            right = 0;
            space = 0;
            Dungeon();
        }
    }
}
#endif