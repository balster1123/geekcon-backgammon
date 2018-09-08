#include "GameManager.h"


GameManager::GameManager(Adafruit_WS2801& ledStrip)
{
    InitBoard();
    displayManager = &DisplayManager(ledStrip, &board);
}

void GameManager::InitBoard()
{
    joystick_location = 0;
    selected_location = LOCATION_INVALID;
    board.Init();
}

void GameManager::HandleTick()
{
    displayManager->DisplayBoard(joystick_location, selected_location);
}

bool GameManager::PlayerRequestedPointerMove(Directions_t direction)
{
    if (direction == DIRECTION_LEFT)
    {
        if ((LOCATION_ROAD_MIN <= joystick_location) &&
            (joystick_location < LOCATION_ROAD_FIRST_HALF_MAX))
        {
            joystick_location++;
            return true;
        }

        if ((LOCATION_ROAD_SECOND_HALF_MIN < joystick_location) &&
            (joystick_location <= LOCATION_ROAD_MAX))
        {
            joystick_location--;
            return true;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_DEADPOOL_2;
            return true;
        }

        if (LOCATION_FINISHED == joystick_location)
        {
            joystick_location = LOCATION_DEADPOOL_1;
            return true;
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
            return true;
        }

        if ((LOCATION_ROAD_SECOND_HALF_MIN <= joystick_location) &&
            (joystick_location < LOCATION_ROAD_MAX))
        {
            joystick_location++;
            return true;
        }

        if (LOCATION_DEADPOOL_2 == joystick_location)
        {
            joystick_location = LOCATION_DEADPOOL_1;
            return true;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_FINISHED;
            return true;
        }
    }

    if (direction == DIRECTION_UP)
    {
        if ((LOCATION_ROAD_MIN <= joystick_location) &&
            (joystick_location <= LOCATION_ROAD_FIRST_HALF_MAX))
        {
            if (joystick_location < 6)
            {
                joystick_location = LOCATION_DEADPOOL_1;
            }
            else
            {
                joystick_location = LOCATION_DEADPOOL_2;
            }
            return true;
        }

        if (LOCATION_DEADPOOL_2 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_SECOND_HALF_MIN + 3;
            return true;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_SECOND_HALF_MIN + 9;
            return true;
        }

        if (LOCATION_FINISHED == joystick_location)
        {
            joystick_location = LOCATION_ROAD_MAX;
            return true;
        }
    }

    if (direction == DIRECTION_DOWN)
    {
        if ((LOCATION_ROAD_SECOND_HALF_MIN <= joystick_location) &&
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
            return true;
        }

        if (LOCATION_DEADPOOL_2 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_FIRST_HALF_MAX - 3;
            return true;
        }

        if (LOCATION_DEADPOOL_1 == joystick_location)
        {
            joystick_location = LOCATION_ROAD_FIRST_HALF_MAX - 9;
            return true;
        }

        if (LOCATION_FINISHED == joystick_location)
        {
            joystick_location = LOCATION_ROAD_MIN;
            return true;
        }
    }

    DEBUG("Nothing to do with this move request");
    return false;
}

int GameManager::GetJoystickLocation()
{
    return joystick_location;
}

int GameManager::GetSelectedLocation()
{
    return selected_location;
}

bool GameManager::PlayerPressed()
{
    DEBUG("Player Pressed");

    // Player regretted their selection?
    if (selected_location == joystick_location)
    {
        // Reset the selection
        selected_location = LOCATION_INVALID;
        return true;
    }

    // Nothing is selected yet?
    if (selected_location == LOCATION_INVALID)
    {
        selected_location = joystick_location;
        return true;
    }

    // Something WAS already selected, and now a DIFFERENT thing was?
    // Player wants to make a move
    if ((selected_location != LOCATION_INVALID) &&
        (joystick_location != selected_location))
    {
        board.Move(selected_location, joystick_location);

        // Reset the selection
        selected_location = LOCATION_INVALID;
        return true;
    }

    return false;
}

void GameManager::PrintBoardForDebug()
{
    board.DisplayPieces(joystick_location, selected_location);
}