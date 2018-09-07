#include "Player.h"
#include "Line.h"

#pragma once
class Board
{
public:
	Board();
	void Setup();
	void DisplayPieces();
	void SetOriginPiece(Player player, int index);
	void Move(Player player, int originalIndex, int targetIndex);

private:
    const static int LINES_COUNT = 24;
    Line lines[LINES_COUNT];
	int currentOriginIndex;
	int* validMovementOptions;

};

