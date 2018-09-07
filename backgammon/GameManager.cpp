#include "GameManager.h"


GameManager::GameManager()
{
    joystick_location = 0;
    selected_location = -1;
}

void GameManager::InitBoard()
{

}

void GameManager::PlayerRequestedPointerMove(Directions_t direction)
{
    if (direction == DIRECTION_LEFT)
    {
        joystick_location += 1;
    }
    if (direction == DIRECTION_RIGHT)
    {
        joystick_location -= 1;
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
    selected_location = joystick_location;
}