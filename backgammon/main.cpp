#include "Board.h"
#include "framework.h"

void test()
{
    DEBUG("Starting tests!");
    Board* board = new Board();

    DEBUG("Empty board:");
    board->DisplayPieces();

    DEBUG("Initializing game:");
    board->Setup();
    board->DisplayPieces();    

    DEBUG("Finished tests!");
}

int main()
{
    DEBUG("Hello world!");
    DEBUG("Remember the Arduino uses backgammon.ino as a startup point\n");

    test();
}