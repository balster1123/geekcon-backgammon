#include "GameManager.h"

GameManager::GameManager()
{
    InitBoard();
}

void GameManager::InitBoard()
{
    joystick_location = 0;
    selected_location = -1;
    board.Init();
}

void GameManager::PlayerRequestedPointerMove(Directions_t direction)
{
    if (direction == DIRECTION_LEFT)
    {
		movePointerLeft();
    }
    if (direction == DIRECTION_RIGHT)
    {
		movePointerRight();
    }
}

void GameManager::movePointerRight()
{
	joystick_location--;

	if (joystick_location == -1)
	{
		joystick_location = Board::LINES_COUNT-1;
	}

}

void GameManager::movePointerLeft()
{
	joystick_location++;

	if (joystick_location == Board::LINES_COUNT)
	{
		joystick_location = 0;
	}
}

int GameManager::GetJoystickLocation()
{
    return joystick_location;
}

int GameManager::GetSelectedLocation()
{
    return selected_location;
}

void GameManager::PlayerPressed()
{
    // Player regretted their selection?
    if (selected_location == joystick_location)
    {
        // Reset the selection
        selected_location = -1;
        return;
    }

    // Nothing is selected yet?
    if (selected_location == -1)
    {
        selected_location = joystick_location;
        return;
    }

    // Something WAS already selected, and now a DIFFERENT thing was?
    // Player wants to make a move
    if ((selected_location != -1) &&
        (joystick_location != selected_location))
    {
        board.Move(selected_location, joystick_location);

        // Reset the selection
        selected_location = -1;
        return;
    }
}

void GameManager::PrintBoardForDebug()
{
    board.DisplayPieces(joystick_location, selected_location);
}