#include "GameManager.h"


GameManager::GameManager()
{
    joystick_location = 0;
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