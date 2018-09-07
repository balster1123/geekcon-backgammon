#include "DiceManager.h"



DiceManager::DiceManager()
{
}

int* DiceManager::GetDiceResults()
{
	int results[4] = { 0 };
	for (int i = 0; i < 2; i++)
	{
		results[i] = getDieResult(i);
	}

	if (results[0] == results[1]) // is double
	{
		results[2] = results[3] = results[0];
	}
}

int DiceManager::getDieResult(int dieId)
{

}


void DiceManager::SetTargetFace(int target)
{

}

void DiceManager::SetOppositeFace(int target)
{

}
