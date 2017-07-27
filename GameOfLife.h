/*
  GameOfLife.h
  Created by Artiom FEDOROV 07/2017
  Released into the public domain.
*/

#ifndef GameOfLife_h
#define GameOfLife_h

#include "Arduino.h"
#include "U8glib/U8glib.h"

#define SIZE_X 96
#define SIZE_Y 48

class GameOfLife {
    public:
        GameOfLife();
        int test();
        byte world[SIZE_X * SIZE_Y / 8];
        int world_size = SIZE_X * SIZE_Y / 8;

        void initWorld(int value);
        boolean checkCell(int x, int y, byte world_param[]);
        void setCell(int x, int y, boolean value, byte world_param[]);
        int findIndexInWorld(int x, int y);
        boolean readCellFromByte(int x, byte world_byte);
        byte writeCellByte(int x, boolean value, byte original_byte);

        void drawWorld(byte world_param[]);

};

#endif
