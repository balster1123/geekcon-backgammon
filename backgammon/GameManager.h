#include "Player.h"

#pragma once
class GameManager
{
public:
	GameManager();
	void InitBoard();
protected:
	Player players[2];
private:
	int currentPlayer;
};

