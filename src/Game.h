#pragma once
#include "Constants.h"
#include "BattleCity.h"
class Game
{
public:
	Game();
	~Game();
	void drawMap();
	bool isGameOver();
	bool isVictory();
	void run();
private:
	BattleCity battleCity_;
	int gameTime;
	char field_[Constants::HEIGHT][Constants::WIDTH];
};

