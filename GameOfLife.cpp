#include "GameOfLife.h"
#include "U8glib/U8glib.h"

GameOfLife::GameOfLife() {
    //int b = a;
}


int GameOfLife::test() {
    return 1;
}


void GameOfLife::initWorld(int value) {
    for (int i = 0; i < world_size; i++) {
        // world[i] = random(255);
        world[i] = value;
    }
}


boolean GameOfLife::checkCell(int x, int y, byte world_param[]) {
    int world_index = findIndexInWorld(x,y);
    boolean result = readCellFromByte(x, world_param[world_index]);
    return result;
}


void GameOfLife::setCell(int x, int y, boolean value, byte world_param[]) {
    int world_index = findIndexInWorld(x,y);
    world_param[world_index] = writeCellByte(x, value, world_param[world_index]);
}


int GameOfLife::findIndexInWorld(int x, int y) {

    // find the line (y value)
    int y_zone = y * (SIZE_X / 8);
    // find the concerned byte in x zone
    int x_zone = (x / 8);
    return y_zone + x_zone;
}


boolean GameOfLife::readCellFromByte(int x, byte world_byte) {
    int modulo_x = x % 8;
    boolean result = false;
    if (world_byte >> (8 - modulo_x)  & 0x01) {
        result = true;
    }
    return result;
}


byte GameOfLife::writeCellByte(int x, boolean value, byte original_byte) {
    int modulo_x = x % 8;
    byte result = 1;
    int int_val = 0;
    if (value) {
        int_val = 1;
    }
    result ^= (-int_val ^ original_byte) & (1 << (8 - modulo_x));
    return result;
}


/*
void GameOfLife::drawWorld(byte world_param[]){
    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            if(checkCell(i, j, world)) {
                drawPixel(i,j);
            }
        }
    }
}
*/
