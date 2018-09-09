#include "Settings.h"

uint32_t Color(uint8_t r, uint8_t g, uint8_t b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

uint32_t GetPlayerColors(int playerId, int overflowCount = 0)
{
	switch (playerId)
	{
   		case PLAYER_FIRST:
   			switch (overflowCount)
   			{
   				case 0:
   					return Color(100, 0, 0);
   				case 1:
   					return Color(150, 20, 0);
   				case 2:
   					return Color(200, 50, 0);
   				case 3:
   					return Color(255, 200, 0);
   			}
      		break;
    	case PLAYER_SECOND:
   			switch (overflowCount)
   			{
   				case 0:
   					return Color(0, 0, 100);
   				case 1:
   					return Color(0, 20, 150);
   				case 2:
   					return Color(0, 50, 200);
   				case 3:
   					return Color(0, 200, 255);
   			}
			break;
	}
}

uint32_t GetBinaryColor(int playerId)
{
  switch (playerId)
  {
    case PLAYER_FIRST:
      return Color(255, 0, 0);
    case PLAYER_SECOND:
      return Color(0, 0, 255);
    default:
      return Color(0, 255, 0);
  }
}

