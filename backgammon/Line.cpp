#include "Line.h"
#include "framework.h"

Line::Line() : player(PLAYER_NONE), pieces(0)
{
}

Line::Line(Players_t which_player, int num_pieces) : player(which_player), pieces(num_pieces)
{
}

void Line::Print()
{
    if (player != PLAYER_NONE)
    {
        char piece;
        if (player == PLAYER_FIRST)
        {
            piece = '1';
        }
        if (player == PLAYER_SECOND)
        {
            piece = '2';
        }

        char output[pieces + 1]; // Saving this array instead of printing one by one makes it faster
        for (int i = 0; i < pieces; i++)
        {
            output[i] = piece;
        }
        output[pieces] = '\0';
        DEBUG_NONEWLINE(output);
    }
}