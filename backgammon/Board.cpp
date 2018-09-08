#include "Board.h"
#include "framework.h"

Board::Board()
{
}


void Board::Init()
{
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

Line Board::GetLine(int index)
{
    return lines[index];
}

bool Board::Move(int originalIndex, int targetIndex)
{
    Line& fromLine = lines[originalIndex];
    Line& toLine = lines[targetIndex];
    
    if (!isValidMove(fromLine, toLine))
    {
        return false;
    }

	tryEat(toLine, fromLine, targetIndex);

	finalizeMovement(fromLine, toLine);

    return true;
}

bool Board::MoveFromDead(int playerId, int targetIndex)
{
	Line& fromLine = dead_pools[playerId];
	Line& toLine = lines[targetIndex];
    
    if (!isValidMove(fromLine, toLine))
    {
        return false;
    }

	tryEat(toLine, fromLine, targetIndex);

	finalizeMovement(fromLine, toLine);

    return true;
}

bool Board::MoveToDead(int originIndex)
{
	Line& fromLine = lines[originIndex];
	Line& toLine = dead_pools[fromLine.player];

	finalizeMovement(fromLine, toLine);

    return true;
}

bool Board::MoveToFinish(int originIndex)
{
	Line& fromLine = lines[originIndex];
	Line& toLine = finished_pools[fromLine.player];

	finalizeMovement(fromLine, toLine);

    return true;
}

bool Board::isValidMove(Line& fromLine, Line& toLine)
{
    // is the place occupied by the opponent 
    if (toLine.player == 3 - fromLine.player &&
        toLine.pieces > 1)
    {
        return false;
    }

    return true;
}

void Board::tryEat(Line & toLine, Line& fromLine, int targetIndex)
{
	if ((toLine.player != fromLine.player) &&
		(toLine.player != PLAYER_NONE) &&
		(toLine.pieces == 1))
	{
		MoveToDead(targetIndex);
	}
}

void Board::finalizeMovement(Line& fromLine, Line& toLine)
{
	toLine.player = fromLine.player;
	fromLine.pieces -= 1;
	toLine.pieces += 1;
}