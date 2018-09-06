#include "Colour.h"

#pragma once
class Player
{
public:
	Colour colour;
	Player(int newPlayerId);

protected:
	int id;

private:
	int finishedCounter;
};

