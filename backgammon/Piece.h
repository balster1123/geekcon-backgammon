#include "Colour.h"

#pragma once
class Piece
{
public:
	Piece();
	Colour* GetColour();

protected:
	int id;
	int playerId;
};

