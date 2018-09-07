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
}

void Board::SetOriginPiece(Player player, int index)
{

}


void Board::Move(Player player, int originalIndex, int targetIndex)
{

}