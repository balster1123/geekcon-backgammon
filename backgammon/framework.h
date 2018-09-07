#pragma once

#include "Settings.h"

#ifndef ARDUINO_PLATFORM
#include <iostream>
#endif

typedef enum Players
{ 
    PLAYER_FIRST = 1,
    PLAYER_SECOND = 2,
    PLAYER_NONE = 0,
} Players_t;


#ifdef ARDUINO_PLATFORM
#define DEBUG
#else

class Log
{
public:
    static void debug(const char* text, bool newline = true)
    {
        printf("%s", text);

        if (newline)
        {
            printf("\n");
        }
    }
    static void debug(std::string& text, bool newline = true)
    {
        debug(text.c_str(), newline);
    }
};

#define DEBUG Log::debug
#endif