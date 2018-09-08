#include "Adafruit_WS2801.h"
#include "Board.h"
#include "Line.h"
#include "framework.h"

#pragma once
class DisplayManager
{
public:
	DisplayManager(Adafruit_WS2801 newStrip, Board* board);
	void DisplayBoard(int joystick_location, int selected_location);
private:
	Adafruit_WS2801 strip;
	Board* board;

	void clearBoard();
	void displayLine(int index);
  void displayLineBinary(Line line, int lineIndex);
  void displayLineCumulative(Line line, int lineIndex);
  void displayLed(int lineIndex, int ledIndex, uint32_t color);
  void displayLonelyLine(Line* line, int first_led_index, int led_count);

};
