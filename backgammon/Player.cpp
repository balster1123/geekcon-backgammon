#include "Player.h"
#include "Settings.h"


Settings s = Settings();

Player::Player(int newPlayerId)
{
	id = newPlayerId;
	switch (id)
	{
	case 1:
		colour = s.Player1Colour;
		break;
	case 2:
		colour = s.Player2Colour;
		break;
	default:
		break;
	}
	finishedCounter = 0;
}
