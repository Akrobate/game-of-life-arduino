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


boolean checkCell(int x, int y) {

    boolean a = true;


    return a;
}
