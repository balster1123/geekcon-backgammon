#include <stdint.h>

#pragma once

#define LINES_AMOUNT 24
#define PIXELS_PER_LINE 5

#define IS_DISPLAY_BINARY false

typedef enum Players
{ 
    PLAYER_FIRST = 0,
    PLAYER_SECOND = 1,
    PLAYER_NONE = -1,
} Players_t;

// Create a 24 bit color value from R,G,B
uint32_t Color(uint8_t r, uint8_t g, uint8_t b);

uint32_t GetPlayerColors(int playerId, int overflowCount = 0);

// Platform
#define ARDUINO_PLATFORM // Only define this when running on an Arduino; Comment out when running on a laptop
