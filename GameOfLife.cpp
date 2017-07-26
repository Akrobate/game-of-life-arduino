#include "GameOfLife.h"

GameOfLife::GameOfLife() {

}


int GameOfLife::test() {
    return 1;
}


void GameOfLife::initWorld() {
    for (int i = 0; i < world_size; i++) {
        world[i] = random(255);
    }
}


boolean GameOfLife::checkCell(int x, int y) {
    boolean a = true;
    return a;
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
