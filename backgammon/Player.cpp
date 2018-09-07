#include "Player.h"
#include "Settings.h"

Player::Player(int newPlayerId)
{
	id = newPlayerId;
	switch (id)
	{
	case 1:
		Player1Colour;
		break;
	case 2:
		Player2Colour;
		break;
	default:
		break;
	}
	finishedCounter = 0;
}
