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
#include <SoftwareSerial.h>
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif


#define DEBUG Serial.println
#define DEBUG_NONEWLINE Serial.print
#else

class NonArduinoLog
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

#define DEBUG NonArduinoLog::debug

// The following is a mistake, it will still create a new line:
#define DEBUG_NONEWLINE NonArduinoLog::debug
#endif