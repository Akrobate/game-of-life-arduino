/*
  GameOfLife.h
  Created by Artiom FEDOROV 07/2017
  Released into the public domain.
*/

#ifndef GameOfLife_h
#define GameOfLife_h

#include "Arduino.h"


#define SIZE_X 96
#define SIZE_Y 48

class GameOfLife {
    public:
        GameOfLife();
        int test();
        byte world[SIZE_X * SIZE_Y / 8];
        int world_size = SIZE_X * SIZE_Y / 8;

        void initWorld();
        boolean checkCell(int x, int y);

};

#endif
