#include "DisplayManager.h"
#include <math.h>

DisplayManager::DisplayManager(Adafruit_WS2801 newStrip, Board* newBoard)
{
	strip = newStrip;
	board = newBoard;
}

void DisplayManager::DisplayBoard()
{
  
}

void DisplayManager::clearBoard()
{
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, Color(0,0, 0));
    }
}

void DisplayManager::displayLine(int lineIndex)
{
    Line line = board->GetLine(lineIndex);

    if (line.player == PLAYER_NONE)
    {
      return;
    }

    int ledIndex = PIXELS_PER_LINE * lineIndex;
    /*if (IS_DISPLAY_BINARY)
    {
      displayLineBinary(line, ledIndex);
    }
    else
    {*/
      displayLineCumulative(line, lineIndex, ledIndex);
    //}
}

void DisplayManager::displayLineBinary(Line line, int lineIndex, int ledIndex)
{
  
}

void DisplayManager::displayLineCumulative(Line line, int lineIndex, int ledIndex)
{
  int overflows = floor(line.pieces / PIXELS_PER_LINE);
  int remainder = line.pieces % PIXELS_PER_LINE;

  // First LED is for the cursor
  for (int i = 1; i < PIXELS_PER_LINE; i++)
  {
    uint32_t color = Color(0, 0, 0);
    
    if (i <= remainder) {
      color = GetPlayerColors(line.player, overflows);
    } else if (overflows > 0) {
      color = GetPlayerColors(line.player, overflows - 1);
    }

    displayLed(lineIndex, ledIndex, color);
  }
}

void DisplayManager::displayLed(int lineIndex, int ledIndex, uint32_t color)
{
  strip.setPixelColor((PIXELS_PER_LINE * lineIndex) + ledIndex, color);
}
