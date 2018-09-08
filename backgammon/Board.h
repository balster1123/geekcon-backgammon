#include "Line.h"

#pragma once
class Board
{
public:
	Board();
	void Init();
	void DisplayPieces(int joystick_location = -1, int selected_location = -1);
    Line GetLine(int index);
    
    const static int LINES_COUNT = 24;

    // void SetOriginPiece(Player player, int index); // Yonatan: What is this? (It doesn't compile, commenting out since I don't understand it)

    // Returns whether a move was successful
    bool Move(int originalIndex, int targetIndex);

	void tryEat(Line * toLine, Line * fromLine, int targetIndex);
	bool MoveToDead(int originIndex);
private:
	bool isValidMove(Line* fromLine, Line* toLine);
	bool isValidDirection(int player, int originIndex, int targetIndex);
    void finalizeMovement(Line* fromLine, Line* toLine);
    Line* GetLineByLocation(int location, Players_t which_player = PLAYER_NONE);

    Line lines[LINES_COUNT];
    Line dead_pools[2]; // Pieces that were eaten. Note the location in the array goes by the "enum Players"
    Line finished_pools[2]; // Pieces that finished the game. Note the location in the array goes by the "enum Players"

	int currentOriginIndex;
	int* validMovementOptions;

};

