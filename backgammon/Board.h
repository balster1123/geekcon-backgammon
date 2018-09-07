#include "Line.h"

#pragma once
class Board
{
public:
	Board();
	void Init();
	void DisplayPieces(int joystick_location = -1, int selected_location = -1);
	// void SetOriginPiece(Player player, int index); // Yonatan: What is this? (It doesn't compile, commenting out since I don't understand it)
	void Move(Players_t player, int originalIndex, int targetIndex);

private:
    const static int LINES_COUNT = 24;
    Line lines[LINES_COUNT];
	int currentOriginIndex;
	int* validMovementOptions;

};

