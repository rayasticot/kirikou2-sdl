#ifndef SKULL_H
#define SKULL_H

void skullDeath(int i);

void skullStart(int i, struct map carte, int px, int py, int sprite){
    createImage("sprite/skulatef.png", i, px, px);
    rect[i].x = px;
    rect[i].y = py;
    skullLive[i] = true;
    dir[i] = 0;
}
void skullUpdate(int i){
    int16_t tempxskulx, tempxskuly;
    if(rect[i].x < 0){
        dir[i] = 1;
        tempxskulx = rect[i].x;
        tempxskuly = rect[i].y;
        destroyImage(i);
        createImage("sprite/skulate.png", i, tempxskulx, tempxskuly);
    }
    if(rect[i].x > 864){
        dir[i] = 0;
        tempxskulx = rect[i].x;
        tempxskuly = rect[i].y;
        destroyImage(i);
        createImage("sprite/skulatef.png", i, tempxskulx, tempxskuly);
    }
    if(dir[i] == 0){
        rect[i].x -= 8;
    }
    else{
        rect[i].x += 8;
    }
    if(checkCollision(rect[1].x, rect[1].y, 64, 128, rect[i].x, rect[i].y, 128, 128) == true){
        alive = false;
    }
    if(checkCollision(rect[2].x, rect[2].y, 32, 32, rect[i].x, rect[i].y, 128, 128) == true){
        skullDeath(i);
        bul = false;
        lock = false;
        rect[2].x = 1024;
    }
}
void skullDeath(int i){
    rect[i].y = 768;
    destroyImage(i);
    skullLive[i] = false;
}
#endif