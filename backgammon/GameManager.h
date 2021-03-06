#pragma once

#include "Board.h"
#include "DisplayManager.h"

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
	GameManager(Adafruit_WS2801& ledStrip);
	void InitBoard();
    void HandleTick();
    bool PlayerRequestedPointerMove(Directions_t direction);
    int GetJoystickLocation();
    
    // Where the player selected - and probably wants to move from here. -1 if nothing is selected
    int GetSelectedLocation();

    // Player pressed the joystick in the current location.
    bool PlayerPressed();
    void PrintBoardForDebug();

private:
	int currentPlayer;
    int joystick_location; // Where is the player pointing at with the joystick?
    int selected_location; // See GetSelectedLocation()
    Board board;
    DisplayManager* displayManager;

	void movePointerRight();
	void movePointerLeft();
};
