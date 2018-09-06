

#pragma once
class DiceManager
{
public:
	DiceManager();
	int* GetDiceResults();
	void SetTargetFace(int target);
	void SetOppositeFace(int target);
};
