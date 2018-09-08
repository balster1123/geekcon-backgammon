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

// These locations are for joystick_location and selected_location;
// They have NOTHING to do with the leds / ascii / other-ui representations
const int LOCATION_ROAD_MIN = 0;
const int LOCATION_ROAD_FIRST_HALF_MAX = 11;
const int LOCATION_ROAD_SECOND_HALF_MIN = 12;
const int LOCATION_ROAD_MAX = 23;
const int LOCATION_INVALID = -100;
const int LOCATION_DEADPOOL_1 = -1;
const int LOCATION_DEADPOOL_2 = -2;
const int LOCATION_FINISHED = -3;

class GameManager
{
public:
    GameManager();
	GameManager(Adafruit_WS2801& ledStrip);
	void InitBoard();
    void HandleTick();

    void PlayerRequestedPointerMove(Directions_t direction);
    int GetJoystickLocation();
    
    // Where the player selected - and probably wants to move from here. -1 if nothing is selected
    int GetSelectedLocation();

    // Player pressed the joystick in the current location.
    void PlayerPressed();
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

