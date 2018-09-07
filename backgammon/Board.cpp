#include "Board.h"
#include "framework.h"

Board::Board()
{
}


void Board::Init()
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

    dead_pools[PLAYER_FIRST].player = PLAYER_FIRST;
    dead_pools[PLAYER_SECOND].player = PLAYER_SECOND;
    finished_pools[PLAYER_FIRST].player = PLAYER_FIRST;
    finished_pools[PLAYER_SECOND].player = PLAYER_SECOND;
}


void Board::DisplayPieces(int joystick_location, int selected_location)
{
    DEBUG("--------------------------------");
    DEBUG("--------------------------------");
    DEBUG("Board:");
    for(int line_index = 0; line_index < LINES_COUNT; line_index++)
    {
        if (joystick_location == line_index)
        {
            DEBUG_NONEWLINE("J");
        }
        else
        {
            DEBUG_NONEWLINE(" ");
        }

        if (selected_location == line_index)
        {
            DEBUG_NONEWLINE("S");
        }
        else
        {
            DEBUG_NONEWLINE(" ");
        }

        Line line = lines[line_index];

        line.Print();

        DEBUG("");
    }
    DEBUG("Dead pool: ");
    dead_pools[PLAYER_FIRST].Print();
    dead_pools[PLAYER_SECOND].Print();
    DEBUG("");
    DEBUG("Finished pool: ");
    finished_pools[PLAYER_FIRST].Print();
    finished_pools[PLAYER_SECOND].Print();
    DEBUG("");
}

/*void Board::SetOriginPiece(Player player, int index)
{

}*/


bool Board::Move(int originalIndex, int targetIndex)
{
    Line& fromLine = lines[originalIndex];
    Line& toLine = lines[targetIndex];

    // Eating?
    if ((toLine.player != fromLine.player) &&
        (toLine.player != PLAYER_NONE))
    {
        // One was eaten
		MoveToDead(1 - fromLine.player, targetIndex);
    }

    toLine.player = fromLine.player;
    fromLine.pieces -= 1;
    toLine.pieces += 1;
}

bool Board::MoveFromDead(int playerId, int targetIndex)
{
	Line& fromLine = dead_pools[playerId];
	Line& toLine = lines[targetIndex];
	]

	// Eating?
	if ((toLine.player != fromLine.player) &&
		(toLine.player != PLAYER_NONE) &&
		(toLine.pieces == 1))
	{
		// One was eaten
		MoveToDead(1 - playerId, targetIndex);
	}

	finalizeMovement();
}

bool Board::MoveToDead(int playerId, int originIndex)
{
	Line& fromLine = lines[originIndex];
	Line& toLine = dead_pools[playerId];

	finalizeMovement(fromLine, toLine);
}

bool Board::MoveToFinish(int playerId, int originIndex)
{
	Line& fromLine = lines[originIndex];
	Line& toLine = finished_pools[playerId];

	finalizeMovement(fromLine, toLine);
}

void Board::finalizeMovement(Line fromLine, Line toLine)
{
	toLine.player = fromLine.player;
	fromLine.pieces -= 1;
	toLine.pieces += 1;
}