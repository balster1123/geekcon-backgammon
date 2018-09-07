#include "framework.h"

#pragma once

class Line
{
public:
    Players_t player; // The player who has pieces in this line
    int pieces; // How many pieces does this player have?
    Line();
    Line(Players_t which_player, int num_pieces);
};

