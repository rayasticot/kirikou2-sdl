#ifndef BOLE_H
#define BOLE_H

void boleStart(int i, struct map carte, int px, int py){
    createImage(list[levelindex].link[6], i, px, py);
}
void boleUpdate(int i, struct map carte){
    if(checkCollision(rect[1].x, rect[1].y, 64, 128, carte.obj_x[i]*4, carte.obj_y[i]*4, 128, 128) == true){
        loadCine(carte.cinematic);
        if(left == 1){
            rect[1].x = (carte.obj_x[i]*4)-128;
        }
        if(right == 1){
            rect[1].x = (carte.obj_x[i]*4)+128;
        }
        if(up == 1){
            rect[1].y = (carte.obj_y[i]*4)-128;
        }
        if(down == 1){
            rect[1].y = (carte.obj_y[i]*4)+128;
        }
        up = 0;
		down = 0;
		left = 0;
		right = 0;
        space = 0;
    }
}
#endif