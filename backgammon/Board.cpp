#include "Board.h"


Board::Board()
{
}


void Board::Setup()
{
	lines[5] = Line(1, 5);
	lines[7] = Line(1, 3);
	lines[12] = Line(1, 5);
	lines[23] = Line(1, 2);

	lines[19] = Line(2, 5);
	lines[17] = Line(2, 3);
	lines[11] = Line(2, 5);
	lines[0] = Line(2, 2);

	currentOriginIndex = -1;
	validMovementOptions = {};
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