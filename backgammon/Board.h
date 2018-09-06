#include "Player.h"
#include "Line.h"

#pragma once
class Board
{
public:
	Board();
	void DisplayPieces();
	void SetOriginPiece(Player player, int index);
	void Move(Player player, int originalIndex, int targetIndex);

private:
    Line lines[24];
	int currentOriginIndex;
	int* validMovementOptions;

};

