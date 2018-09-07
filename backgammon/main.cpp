#define UNIT_TESTS 1
#ifdef UNIT_TESTS

#include <iostream>

#include "Board.h"
#include "framework.h"

void test()
{
    Log::debug("Starting tests!");
    Board* board = new Board();

    Log::debug("Empty board:");
    board->DisplayPieces();

    Log::debug("Initializing game:");
    board->Setup();
    board->DisplayPieces();    

    Log::debug("Finished tests!");
}

int main()
{
    Log::debug("Hello world!");
    Log::debug("Remember the Arduino uses backgammon.ino as a startup point\n");

    test();
}

#endif