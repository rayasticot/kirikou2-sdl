#ifndef KIRIKOU_H
#define KIRIKOU_H

#define false 0
#define true 1

int mx = 1;
int my = 1;
_Bool buldir = false;
_Bool bul = false;
_Bool lock = false;
uint8_t speed = 4;

void movementCheckFin();
void loadRoom();

void kirikouGunStart(){
    createImage("sprite/kirikougun.png", 1, rect[1].x, rect[1].y);
}

void kirikouStart(int px, int py){
    createImage("sprite/kirikouvide.png", 1, px, py);
}

void kirikouUpdate(){
    if(space == 1){
        speed = 8;
    }
    else{
        speed = 4;
    }
    if(right == 1){
        rect[1].x += speed;
    }
    if(left == 1){
        rect[1].x -= speed;
    }
    if(down == 1){
        rect[1].y += speed;
    }
    if(up == 1){
        rect[1].y -= speed;
    }
    if(rect[1].x > 1024){
        rect[1].x = 1024;
        if(mx < 2){
            //pos[mx][my] = 0;
            mx += 1;
            rect[1].x = 0;
            movementCheckFin();
        }
    }
    if(rect[1].x < -64){
        rect[1].x = -64;
        if(mx > 0){
            //pos[mx][my] = 0;
            mx -= 1;
            rect[1].x = 960;
            movementCheckFin();
        }
    }
    if(rect[1].y > 768){
        rect[1].y = 768;
        if(my < 2){
            //pos[mx][my] = 0;
            my += 1;
            rect[1].y = 0;
            movementCheckFin();
        }
    }
    if(rect[1].y < -128){
        rect[1].y = -128;
        if(my > 0){
            //pos[mx][my] = 0;
            my -= 1;
            rect[1].y = 640;
            movementCheckFin();
        }
    }
}

void kirikouGunUpdate(){
    int16_t tempxsulx, tempxsuly;
    if(right == 1){
        if(lock == false){
            buldir = false;
        }
        rect[1].x += 4;
        tempxsulx = rect[1].x;
        tempxsuly = rect[1].y;
        destroyImage(1);
        createImage("sprite/kirikougun.png", 1, tempxsulx, tempxsuly);
    }
    if(left == 1){
        if(lock == false){
            buldir = true;
        }
        rect[1].x -= 4;
        //NF_HflipSprite(1, 0, true);
        tempxsulx = rect[1].x;
        tempxsuly = rect[1].y;
        destroyImage(1);
        createImage("sprite/kirikougunf.png", 1, tempxsulx, tempxsuly);
    }
    if(down == 1){
        rect[1].y += 4;
    }
    if(up == 1){
        rect[1].y -= 4;
    }
    if(rect[1].x > 1024){
        opos = cpos;
        cpos += 1;
        rect[1].x = 0;
        loadRoom(dung[gameState][cpos], dung[gameState][opos]);
    }
    if(rect[1].x < 0){
        rect[1].x = 0;
    }
    if(rect[1].y > 768){
        rect[1].y = 768;
    }
    if(rect[1].y < 0){
        rect[1].y = 0;
    }
    if(space == 1){
        if(lock == false){
            bul = true;
            lock = true;
            //buldir = NF_GetSpriteHflip(1, 0);
            createImage("sprite/bullets.png", 2, rect[1].x, rect[1].y);
            space = 0;
        }
    }
}

void movementCheckFin(){
    //pos[mx][my] = 1;
    switch(levelindex){ // Je suis un flemmard :) :) :) :) :) :)
        case 0:
            loadRoom(benin[mx][my], current);
            break;
        case 1:
            loadRoom(spain[mx][my], current);
            break;
        case 2:
            loadRoom(franc[mx][my], current);
            break;
        case 3:
            loadRoom(retour[mx][my], current);
            break;
    }
}
void bulletUpdate(){
    if(bul == true){
        if(buldir == false){
            rect[2].x += 12;
        }
        else{
            rect[2].x -= 12;
        }
        if(rect[2].x < -64 || rect[2].x > 1024){
            bul = false;
            lock = false;
        }
    }
}
#endif