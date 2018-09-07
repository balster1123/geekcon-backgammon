#include <iostream>


#include "Board.h"
#include "framework.h"

Board::Board()
{
}


void Board::Setup()
{
    Players_t a = PLAYER_FIRST;
	lines[5] = Line(PLAYER_FIRST, 5);
	lines[7] = Line(PLAYER_FIRST, 3);
	lines[12] = Line(PLAYER_FIRST, 5);
	lines[23] = Line(PLAYER_FIRST, 2);

	lines[19] = Line(PLAYER_SECOND, 5);
	lines[17] = Line(PLAYER_SECOND, 3);
	lines[11] = Line(PLAYER_SECOND, 5);
	lines[0] = Line(PLAYER_SECOND, 2);

	currentOriginIndex = -1;
	//validMovementOptions = {};
}


void Board::DisplayPieces()
{
    for(int line_index = 0; line_index < LINES_COUNT; line_index++)
    {
        Line line = lines[line_index];

        if (line.player != PLAYER_NONE)
        {
            std::string piece;
            if (line.player == PLAYER_FIRST)
            {
                piece = "1";
            }
            if (line.player == PLAYER_SECOND)
            {
                piece = "2";
            }

            for (int i = 0; i < line.pieces; i++)
            {
                Log::debug(piece, false);
            }
        }

        Log::debug("");
    }
}

void Board::SetOriginPiece(Player player, int index)
{

}


void Board::Move(Player player, int originalIndex, int targetIndex)
{

}