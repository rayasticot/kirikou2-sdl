#ifndef NPC_H
#define NPC_H
int sindex = 1;
void npcStart(int i, int x, int y, int sprite){
    createImage(list[levelindex].link[sprite-6], i, x, y);
}

void npcUpdate(int i, int posx, int posy){
    if(checkCollision(rect[1].x, rect[1].y, 64, 128, rect[i+5].x, rect[i+5].y, 64, 128) == true){
        Mix_HaltChannel(-1);
        if(left == 1){
            rect[1].x = (current.obj_x[i]*4)-64;
        }
        if(right == 1){
            rect[1].x = (current.obj_x[i]*4)+64;
        }
        if(up == 1){
            rect[1].y = (current.obj_y[i]*4)-128;
        }
        if(down == 1){
            rect[1].y = (current.obj_y[i]*4)+128;
        }
        Mix_PlayChannel(-1, sound[sindex], 0);
        if(sindex != 4){
            sindex += 1;
        }
        else{
            sindex = 0;
        }
    }
}
#endif