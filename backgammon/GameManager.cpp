#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::GameManager(Adafruit_WS2801 ledStrip)
{
    InitBoard();
    displayManager = &DisplayManager(ledStrip, &board);
}

void GameManager::InitBoard()
{
    joystick_location = 0;
    selected_location = -1;
    board.Init();
}

void GameManager::HandleTick()
{
    displayManager->DisplayBoard();
}

void GameManager::PlayerRequestedPointerMove(Directions_t direction)
{
    if (direction == DIRECTION_LEFT)
    {
        if ((LOCATION_ROAD_MIN <= joystick_location) &&
            (joystick_location < LOCATION_ROAD_FIRST_HALF_MAX))
        {
            joystick_location++;
            return;
        }

        if ((LOCATION_ROAD_SECOND_HALF_MIN < joystick_location) &&
            (joystick_location <= LOCATION_ROAD_MAX))
        {
            joystick_location--;
            return;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_DEADPOOL_2;
            return;
        }

        if (LOCATION_FINISHED == joystick_location)
        {
            joystick_location = LOCATION_DEADPOOL_1;
            return;
        }
    }
    if (direction == DIRECTION_RIGHT)
    {
        if ((joystick_location == LOCATION_ROAD_MIN) ||
            (joystick_location == LOCATION_ROAD_MAX))
        {
            joystick_location = LOCATION_FINISHED;
        }

		if ((LOCATION_ROAD_MIN < joystick_location) &&
            (joystick_location <= LOCATION_ROAD_FIRST_HALF_MAX))
        {
            joystick_location--;
            return;
        }

        if ((LOCATION_ROAD_SECOND_HALF_MIN <= joystick_location) &&
            (joystick_location < LOCATION_ROAD_MAX))
        {
            joystick_location++;
            return;
        }

        if (LOCATION_DEADPOOL_2 == joystick_location)
        {
            joystick_location = LOCATION_DEADPOOL_1;
            return;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_FINISHED;
            return;
        }
    }

    if (direction == DIRECTION_UP)
    {
        if ((LOCATION_ROAD_MIN < joystick_location) &&
            (joystick_location <= LOCATION_ROAD_FIRST_HALF_MAX))
        {
            if (joystick_location < 6)
            {
                joystick_location = LOCATION_DEADPOOL_2;
            }
            else
            {
                joystick_location = LOCATION_DEADPOOL_1;
            }
            return;
        }

        if (LOCATION_DEADPOOL_2 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_SECOND_HALF_MIN + 3;
            return;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_SECOND_HALF_MIN + 9;
            return;
        }

        if (LOCATION_FINISHED == joystick_location)
        {
            joystick_location = LOCATION_ROAD_MAX;
            return;
        }
    }

    if (direction == DIRECTION_DOWN)
    {
        if ((LOCATION_ROAD_SECOND_HALF_MIN < joystick_location) &&
            (joystick_location <= LOCATION_ROAD_MAX))
        {
            if (joystick_location < LOCATION_ROAD_SECOND_HALF_MIN + 6)
            {
                joystick_location = LOCATION_DEADPOOL_2;
            }
            else
            {
                joystick_location = LOCATION_DEADPOOL_1;
            }
            return;
        }

        if (LOCATION_DEADPOOL_2 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_FIRST_HALF_MAX - 3;
            return;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_FIRST_HALF_MAX - 9;
            return;
        }

        if (LOCATION_FINISHED == joystick_location)
        {
            joystick_location = LOCATION_ROAD_MIN;
            return;
        }
    }

    DEBUG("Nothing to do with this move request");
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