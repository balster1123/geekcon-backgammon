#pragma once

typedef enum Players
{ 
    PLAYER_FIRST = 1,
    PLAYER_SECOND = 2,
    PLAYER_NONE = 0,
} Players_t;

class Line
{
public:
    Players_t player; // The player who has pieces in this line
    int pieces; // How many pieces does this player have?
    Line();
};

