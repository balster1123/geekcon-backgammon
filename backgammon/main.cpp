#include <iostream>

#include "Board.h"


void test()
{
    printf("Starting tests!\n");
    Board* board = new Board();

    printf("Empty board:\n");
    board->DisplayPieces();

    printf("Initializing game:\n");
    board->Setup();
    board->DisplayPieces();    

    printf("Finished tests!\n");
}

int main()
{
    printf("Hello world!\n");
    printf("Remember the Arduino uses backgammon.ino as a startup point\n\n");

    test();
}
