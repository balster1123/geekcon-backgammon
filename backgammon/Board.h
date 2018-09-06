#include <Piece.h>
#include <Player.h>

#pragma once
class Board
{
public:
	Board();
	void DisplayPieces();
	void SetOriginPiece(Player player, int index);
	void Move(Player player, int originalIndex, int targetIndex);

private:
	Piece pieces[24][12];
	int currentOriginIndex;
	int* validMovementOptions;
};

