#include <iostream>

#include "Board.h"


void test()
{
    printf("Starting tests!\n");
    Board* board = new Board();

    board->DisplayPieces();

    printf("Finished tests!\n");
}

int main()
{
    printf("Hello world!\n");
    printf("Remember the Arduino uses backgammon.ino as a startup point\n\n");

    test();
}
