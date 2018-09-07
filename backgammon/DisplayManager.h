#pragma once
class DisplayManager
{
public:
	DisplayManager(Adafruit_WS2801 newStrip, Board* board);
	void DisplayBoard();
private:
	Adafruit_WS2801 strip;
	Board* board;

	void clearBoard();
	void displayLine(int index);
};

