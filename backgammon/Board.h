#include "Line.h"

#pragma once
class Board
{
public:
	const static int LINES_COUNT = 24;
	Board();
	void Init();
	void DisplayPieces(int joystick_location = -1, int selected_location = -1);

    // void SetOriginPiece(Player player, int index); // Yonatan: What is this? (It doesn't compile, commenting out since I don't understand it)

    // Returns whether a move was successful
    bool Move(int originalIndex, int targetIndex);
	bool MoveFromDead(int playerId, int targetIndex);
	bool MoveToDead(int playerId, int originIndex);
	bool MoveToFinish(int playerId, int originIndex);


private:
    Line lines[LINES_COUNT];
    Line dead_pools[2]; // Pieces that were eaten. Note the location in the array goes by the "enum Players"
    Line finished_pools[2]; // Pieces that finished the game. Note the location in the array goes by the "enum Players"

	int currentOriginIndex;
	int* validMovementOptions;

	void finalizeMovement(Line fromLine, Line toLine);


};

