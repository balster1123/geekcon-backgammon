#pragma once

#include "Board.h"

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
    
    // Where the player selected - and probably wants to move from here. -1 if nothing is selected
    int GetSelectedLocation();

    // Player pressed the joystick in the current location.
    // This will set the location found in GetJoystickLocation --> in to GetSelectedLocation
    void PlayerPressed();
    void PrintBoardForDebug();

private:
	int currentPlayer;
    int joystick_location; // Where is the player pointing at with the joystick?
    int selected_location; // See GetSelectedLocation()
    Board board;
};

