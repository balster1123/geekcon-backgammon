#include <Piece.h>
#include <Player.h>

#pragma once
class Board
{
public:
	Board();
	void DisplayPieces();
	void Move(Player player, int originalIndex, int targetIndex);

protected:
	Piece pieces[24][12];
	
};

