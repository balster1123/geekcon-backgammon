#include <Colour.h>

#pragma once
class Player
{
public:
	Colour colour;
	Player();
	Player(int newPlayerId);

protected:
	int id;

private:
	int finishedCounter;
};

