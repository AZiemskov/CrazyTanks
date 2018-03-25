#pragma once
#include <vector>
#include "Wall.h"
#include "Constants.h"
#include "Tank.h"
#include "Bullet.h"
#include "Enemy.h"
class BattleCity
{
public:
	BattleCity();
	~BattleCity();
	const std::vector<Wall> &getWalls() const;
	const Tank &getTank() const;
	const std::vector<Bullet> &getPlayerBullets() const;
	const std::vector<Enemy> &getEnemies() const;
	const std::vector<Block> &getFortress() const;
	const std::vector<Bullet> &getEnemiesBullets() const;
	const bool& getGoldState() const;
	bool isEnemy(const int j, const int i);
	void playerAction();
	void enemyAction();
	bool chekCollision(const int x, const int y);
	void bulletAction();
private:
	std::vector<Wall> walls_;
	std::vector<Block> fortress_;
	std::vector<Bullet> playerBullets_;
	std::vector<Enemy> enemies_;
	std::vector<Bullet> enemiesBullets_;
	bool goldState_;
	Tank tank_;
	char field_[Constants::HEIGHT][Constants::WIDTH];
};

