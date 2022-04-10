#ifndef BOAT_H
#define BOAT_H
void boatUpdate(int i){
    if(checkCollision(rect[1].x, rect[1].y, 64, 128, current.obj_x[i]*4, current.obj_y[i]*4, 128, 128) == true){
        switch(gameState){
            case 1:
                if(levelindex == 0){
                    levelindex += 1;
                    Ocean(spain[0][2]);
                }
                break;
            case 2:
                if(levelindex == 1){
                    levelindex += 1;
                    Ocean(franc[0][2]);
                }
                break;
            case 3:
                if(levelindex == 2){
                    levelindex += 1;
                    Ocean(retour[0][2]);
                }
                break;
        }
    }
}
#endif