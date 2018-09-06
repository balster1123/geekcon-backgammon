#pragma once

enum Players 
{ 
    First = 1, 
    Second = 2, 
    None = 0 
};

class Line
{
public:
    Players player; // The player who has pieces in this line
    int pieces; // How many pieces does this player have?
    Line();
};

