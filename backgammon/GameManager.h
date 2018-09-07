#include "Player.h"

#pragma once

typedef enum Directions
{ 
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
} Directions_t;

class GameManager
{
public:
	GameManager();
	void InitBoard();
    void PlayerRequestedPointerMove(Directions_t direction);
    int GetJoystickLocation();

private:
	int currentPlayer;
    int joystick_location; // Where is the player pointing at with the joystick?
};

