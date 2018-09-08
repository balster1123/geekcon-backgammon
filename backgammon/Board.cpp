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

Line* Board::GetLineByLocation(int location, Players_t which_player)
{
    if ((LOCATION_ROAD_MIN <= location) &&
        (location <= LOCATION_ROAD_MAX))
    {
        return &lines[location];
    }

    if (LOCATION_INVALID == location)
    {
        return (Line*)0;
    }
    
    if (LOCATION_DEADPOOL_1 == location)
    {
        return &dead_pools[PLAYER_FIRST];
    }

    if (LOCATION_DEADPOOL_2 == location)
    {
        return &dead_pools[PLAYER_SECOND];
    }

    if (LOCATION_FINISHED == location)
    {
        
        if (PLAYER_NONE == which_player)
            return (Line*)0;
            
        return &finished_pools[which_player];
    }

    return (Line*)0;
}

bool Board::Move(int originalIndex, int targetIndex)
{
    if (originalIndex == LOCATION_FINISHED)
    {
        // Invalid move
        DEBUG("Invalid move: From the finished pool");
        return true; // Something still changed
    }

    Line* fromLine = GetLineByLocation(originalIndex);

    if (fromLine->pieces == 0)
    {
        DEBUG("Invalid move: From a place with no pieces");
        return true; // Something still changed
    }

    Line* toLine = GetLineByLocation(targetIndex, fromLine->player);
    
    if (!isValidMove(fromLine, toLine))
    {
        return false;
    }

    /*if (!isValidDirection(fromLine->player, originalIndex, targetIndex))
    {
        DEBUG("Invalid direction");
        return false;
    }*/

	tryEat(toLine, fromLine, targetIndex);

	finalizeMovement(fromLine, toLine);

    return true;
}

bool Board::MoveToDead(int originIndex)
{
	Line* fromLine = &lines[originIndex];
	Line* toLine = &dead_pools[fromLine->player];

	finalizeMovement(fromLine, toLine);

    return true;
}

bool Board::isValidMove(Line* fromLine, Line* toLine)
{
    // is the place occupied by the opponent 
    if (toLine->player == 3 - fromLine->player &&
        toLine->pieces > 1)
    {
        DEBUG("Invalid move - target occupied by opponent");
        return false;
    }

    return true;
}

bool Board::isValidDirection(int player, int originIndex, int targetIndex)
{
    bool isValid = true;
    if ((player == PLAYER_FIRST && originIndex > targetIndex) ||
        (player == PLAYER_SECOND && originIndex < target))
    {
        DEBUG("Invalid move - player can't move in this direction");
        isValid = false;
    }

    return isValid;
}

void Board::tryEat(Line* toLine, Line* fromLine, int targetIndex)
{
	if ((toLine->player != fromLine->player) &&
		(toLine->player != PLAYER_NONE) &&
		(toLine->pieces == 1))
	{
		MoveToDead(targetIndex);
	}
}

void Board::finalizeMovement(Line* fromLine, Line* toLine)
{
	toLine->player = fromLine->player;
	fromLine->pieces -= 1;
	toLine->pieces += 1;
    DEBUG("Moved");
}