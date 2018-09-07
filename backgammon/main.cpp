#include "Board.h"
#include "framework.h"

void test()
{
    DEBUG("Starting tests!");
    Board* board = new Board();

    DEBUG("Empty board:");
    board->DisplayPieces();

    DEBUG("Initializing game:");
    board->Init();
    board->DisplayPieces();    

    DEBUG("Finished tests!");
}

#ifndef ARDUINO_PLATFORM // "main() doesn't allow the normal arduino flow (setup/loop) to run"
int main()
{
    DEBUG("Hello world!");
    DEBUG("Remember the Arduino uses backgammon.ino as a startup point\n");

    test();
}
#endif