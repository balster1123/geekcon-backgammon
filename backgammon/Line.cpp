#include "Line.h"
#include "framework.h"

Line::Line() : player(PLAYER_NONE), pieces(0)
{
}

Line::Line(Players_t which_player, int num_pieces) : player(which_player), pieces(num_pieces)
{
}