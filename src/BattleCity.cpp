#include "stdafx.h"
#include "BattleCity.h"
#include <windows.h>
#include <ctime>

BattleCity::BattleCity()
{
	std::srand(time(0));
	int stopDir = 0;
	int life = 3;
	int score = 0;
	Tank tank(Constants::startTankPosX, Constants::startTankPosY,stopDir,life,score);
	tank_ = tank;
	goldState_ = true;
	Block block1(Constants::WIDTH / 2 - 1, Constants::HEIGHT - 2);
	Block block2(Constants::WIDTH / 2 - 1, Constants::HEIGHT - 3);
	Block block3(Constants::WIDTH / 2 - 3, Constants::HEIGHT - 2);
	Block block4(Constants::WIDTH / 2 - 3, Constants::HEIGHT - 3);
	Block block5(Constants::WIDTH / 2 - 2, Constants::HEIGHT - 3);
	fortress_.push_back(block1);
	fortress_.push_back(block2);
	fortress_.push_back(block3);
	fortress_.push_back(block4);
	fortress_.push_back(block5);
	//walls_.push_back(fortress);
	for (int i = 1; i < Constants::HEIGHT-1; i++) {
		for (int j = 1; j < Constants::WIDTH-1; j++) {
			int isWall = std::rand() % Constants::WIDTH;
			if (isWall == 1 && !chekCollision(j,i)) {
				std::vector<Block> wall;
				int length = std::rand() % 8 + 3;
				int pos =std::rand()%2;
				if (pos == 0) {
					if (length > Constants::WIDTH-1- j) {
						length = Constants::WIDTH-1 - j;
					}
					for (int k = 0; k < length; k++) {
						if (!chekCollision(j, i)) {
							wall.emplace_back(j, i);
							j++;
						}
						else {
							k = length;
						}
					}
					j--;
				}
				else {
					if (length > Constants::HEIGHT-1 - i) {
						length = Constants::HEIGHT-1 - i;
					}
					for (int k = 0; k < length; k++) {
						if (!chekCollision(j, i + k)) {
							wall.emplace_back(j, i + k);
						}
						else {
							k = length;
						}
					}
				}
				walls_.push_back(wall);
			}
		}
	}
	for (int i = 1; i < Constants::HEIGHT - 1; i++) {
		for (int j = 1; j < Constants::WIDTH - 1; j++) {
			if (!chekCollision(j, i)) {
				int isEnemyR = std::rand() % Constants::WIDTH;
				if (isEnemyR == 1 && !isEnemy(j,i)) {
					enemies_.emplace_back(j,i,stopDir);
				}
			}
		}
	}
}


BattleCity::~BattleCity() = default;

const std::vector<Wall>& BattleCity::getWalls() const
{
	return walls_;
}

const Tank & BattleCity::getTank() const
{
	return tank_;
}

const std::vector<Bullet>& BattleCity::getPlayerBullets() const
{
	return playerBullets_;
}

const std::vector<Enemy>& BattleCity::getEnemies() const
{
	return enemies_;
}

const std::vector<Block>& BattleCity::getFortress() const {
	return fortress_;
}

const std::vector<Bullet>& BattleCity::getEnemiesBullets() const
{
	return enemiesBullets_;
}

const bool & BattleCity::getGoldState() const
{
	return goldState_;
}


bool BattleCity::isEnemy(const int j, const int i)
{
	for (int k = 0; k < enemies_.size(); k++) {
		if ((enemies_[k].getPosY() == i - 1 && enemies_[k].getPosX() == j - 1) 
			|| (enemies_[k].getPosY() == i + 1 && enemies_[k].getPosX() == j + 1)
			|| (enemies_[k].getPosY() == i && enemies_[k].getPosX() == j - 1)
			|| (enemies_[k].getPosY() == i - 1 && enemies_[k].getPosX() == j)
			|| (enemies_[k].getPosY() == i + 1 && enemies_[k].getPosX() == j)
			|| (enemies_[k].getPosY() == i && enemies_[k].getPosX() == j + 1)
			|| (enemies_[k].getPosY() == i - 1 && enemies_[k].getPosX() == j + 1)
			|| (enemies_[k].getPosY() == i + 1 && enemies_[k].getPosX() == j - 1)
			|| (enemies_[k].getPosY() == i - 2 && enemies_[k].getPosX() == j - 2)
			|| (enemies_[k].getPosY() == i +2 && enemies_[k].getPosX() == j +2)
			|| (enemies_[k].getPosY() == i && enemies_[k].getPosX() == j - 2)
			|| (enemies_[k].getPosY() == i - 2 && enemies_[k].getPosX() == j)
			|| (enemies_[k].getPosY() == i +2 && enemies_[k].getPosX() == j)
			|| (enemies_[k].getPosY() == i && enemies_[k].getPosX() == j +2)
			|| (enemies_[k].getPosY() == i - 2 && enemies_[k].getPosX() == j +2)
			|| (enemies_[k].getPosY() == i +2 && enemies_[k].getPosX() == j - 2)
			|| (enemies_[k].getPosY() == i - 1 && enemies_[k].getPosX() == j - 1)
			|| (enemies_[k].getPosY() == i - 2 && enemies_[k].getPosX() == j + 1)
			|| (enemies_[k].getPosY() == i +2 && enemies_[k].getPosX() == j - 1)
			|| (enemies_[k].getPosY() == i - 1 && enemies_[k].getPosX() == j +2)
			|| (enemies_[k].getPosY() == i +1 && enemies_[k].getPosX() == j - 2)
			|| (enemies_[k].getPosY() == i - 2 && enemies_[k].getPosX() == j - 1)
			|| (enemies_[k].getPosY() == i - 1 && enemies_[k].getPosX() == j - 2)) {
			return true;
		}
	}
	return false;
}

void BattleCity::playerAction()
{
	if (GetAsyncKeyState(VK_DOWN)) {
		int x = tank_.getPosX();
		int y = tank_.getPosY()+1;
		if (!chekCollision(x, y)) {
			tank_.setPosY(tank_.getPosY() + 1);
		}
		tank_.setDir(Constants::downDir);
	}
	if (GetAsyncKeyState(VK_UP)) {
		int x = tank_.getPosX();
		int y = tank_.getPosY() - 1;
		if (!chekCollision(x, y)) {
			tank_.setPosY(tank_.getPosY() - 1);
		}
		tank_.setDir(Constants::upDir);
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		int x = tank_.getPosX()-1;
		int y = tank_.getPosY();
		if (!chekCollision(x, y)) {
			tank_.setPosX(tank_.getPosX() - 1);
		}
		tank_.setDir(Constants::leftDir);
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		int x = tank_.getPosX()+1;
		int y = tank_.getPosY();
		if (!chekCollision(x, y)) {
			tank_.setPosX(tank_.getPosX() + 1);
		}
		tank_.setDir(Constants::rightDir);
	}
	if(GetAsyncKeyState(VK_SPACE)) {
		playerBullets_.emplace_back(tank_.getPosX(), tank_.getPosY(), tank_.getDir());
	}
}

void BattleCity::enemyAction()
{
	std::srand(time(0));
	for (int i = 0; i < enemies_.size(); i++) {
		int isEnemyAction = std::rand() % 5+1;
		int enemyShoot=5;
		if(isEnemyAction== Constants::downDir) {
			int x = enemies_[i].getPosX();
			int y = enemies_[i].getPosY() + 1;
			bool isTank = (x == tank_.getPosX() && y == tank_.getPosY());
			if (!(chekCollision(x, y) || isTank)) {
				enemies_[i].setPosY(enemies_[i].getPosY() + 1);
				enemies_[i].setDir(Constants::downDir);
			}
		}
	    if (isEnemyAction == Constants::upDir) {
			int x = enemies_[i].getPosX();
			int y = enemies_[i].getPosY() - 1;
			bool isTank = (x == tank_.getPosX() && y == tank_.getPosY());
			if (!(chekCollision(x, y) || isTank)) {
				enemies_[i].setPosY(enemies_[i].getPosY() - 1);
				enemies_[i].setDir(Constants::upDir);
			}
		}
		if (isEnemyAction == Constants::leftDir) {
			int x = enemies_[i].getPosX() - 1;
			int y = enemies_[i].getPosY();
			bool isTank = (x == tank_.getPosX() && y == tank_.getPosY());
			if (!(chekCollision(x, y) || isTank)) {
				enemies_[i].setPosX(enemies_[i].getPosX() - 1);
				enemies_[i].setDir(Constants::leftDir);
			}
		}
		if (isEnemyAction == Constants::rightDir) {
			int x = enemies_[i].getPosX() + 1;
			int y = enemies_[i].getPosY();
			bool isTank = (x == tank_.getPosX() && y == tank_.getPosY());
			if (!(chekCollision(x, y) || isTank)) {
				enemies_[i].setPosX(enemies_[i].getPosX() + 1);
				enemies_[i].setDir(Constants::rightDir);
			}
		}
		if (isEnemyAction == enemyShoot) {
			enemiesBullets_.emplace_back(enemies_[i].getPosX(), enemies_[i].getPosY(), enemies_[i].getDir());
		}
	}
}

bool BattleCity::chekCollision(const int x, const int y)
{
	bool isBorder = (x == 0 || x == Constants::WIDTH - 1 || y == 0 || y == Constants::HEIGHT - 1);
	bool isGold = (x == Constants::posGoldX && y == Constants::posGoldY);
	if (isBorder || isGold) {
		return true;
	}
	for (int i = 0; i < fortress_.size(); i++) {
		bool isFortress = (x == fortress_[i].getPosX() && y == fortress_[i].getPosY());
		if (isFortress) {
			return true;
		}
	}
	for (int i = 0; i < enemies_.size(); i++) {
		bool isEnemy = (x == enemies_[i].getPosX() && y == enemies_[i].getPosY());
		if (isEnemy) {
			return true;
		}
	}
	for (int i = 0; i < walls_.size(); i++) {
		for (int j = 0; j < walls_[i].getLength(); j++) {
			bool isWall = (x == walls_[i][j].getPosX() && y == walls_[i][j].getPosY());
			if (isWall) {
				return true;
			}
		}
	}
	return false;
}

void BattleCity::bulletAction()
{
	for (int i = 0; i < enemiesBullets_.size(); i++) {
		switch (enemiesBullets_[i].getDir()) {
		case 0:
			enemiesBullets_[i].setPosY(enemiesBullets_[i].getPosY() - 1);
			break;
		case 1:
			enemiesBullets_[i].setPosY(enemiesBullets_[i].getPosY() + 1);
			break;
		case 2:
			enemiesBullets_[i].setPosY(enemiesBullets_[i].getPosY() - 1);
			break;
		case 3:
			enemiesBullets_[i].setPosX(enemiesBullets_[i].getPosX() - 1);
			break;
		case 4:
			enemiesBullets_[i].setPosX(enemiesBullets_[i].getPosX() + 1);
			break;
		default:
			break;
		}
		bool isBorder = (enemiesBullets_[i].getPosX() == 0 || enemiesBullets_[i].getPosX() == Constants::WIDTH - 1 ||
			enemiesBullets_[i].getPosY() == 0 || enemiesBullets_[i].getPosY() == Constants::HEIGHT - 1);
		bool isGold = (enemiesBullets_[i].getPosX() == Constants::posGoldX && enemiesBullets_[i].getPosY() == Constants::posGoldY);
		bool isTank= (enemiesBullets_[i].getPosX() == tank_.getPosX() && enemiesBullets_[i].getPosY() == tank_.getPosY());
		if (isTank) {
			enemiesBullets_.erase(enemiesBullets_.begin() + i);
			tank_.setLife(tank_.getLife() - 1);
		}
		else if (isBorder) {
			enemiesBullets_.erase(enemiesBullets_.begin() + i);
		}
		else if (isGold) {
			enemiesBullets_.erase(enemiesBullets_.begin() + i);
			goldState_ = false;
            
		}
		else {
			bool isFriendlyFire = false;
			for (int j = 0; j < enemies_.size(); j++) {
				if (i < enemiesBullets_.size()) {
					bool isEnemy = (enemiesBullets_[i].getPosX() == enemies_[j].getPosX() &&
						enemiesBullets_[i].getPosY() == enemies_[j].getPosY());
					if (isEnemy) {
						enemiesBullets_.erase(enemiesBullets_.begin() + i);
						j == enemies_.size() - 1;
						isFriendlyFire = true;
					}
				}
			}
			if (!isFriendlyFire) {
				bool isFortress = false;
				for (int j = 0; j < fortress_.size(); j++) {
					if (i < enemiesBullets_.size()) {
						bool isFortressTaget = (enemiesBullets_[i].getPosX() == fortress_[j].getPosX() &&
							enemiesBullets_[i].getPosY() == fortress_[j].getPosY());
						if (isFortressTaget) {
							enemiesBullets_.erase(enemiesBullets_.begin() + i);
							fortress_.erase(fortress_.begin() + j);
							j == fortress_.size() - 1;
							isFortress = true;
						}
					}
				}
				if (!isFortress) {
						for (int j = 0; j < walls_.size(); j++) {
							for (int k = 0; k < walls_[j].getLength(); k++) {
								if (i < enemiesBullets_.size()) {
									bool isDestroyBlock = (enemiesBullets_[i].getPosX() == walls_[j][k].getPosX() &&
										enemiesBullets_[i].getPosY() == walls_[j][k].getPosY());
									if (isDestroyBlock) {
										enemiesBullets_.erase(enemiesBullets_.begin() + i);
										walls_[j].destroyBlock(k);
										k = walls_[j].getLength() - 1;
										j = walls_.size() - 1;
									}
								}
							}
						}
					}
				}
			}
		}
	for (int i = 0; i < playerBullets_.size(); i++) {
		switch (playerBullets_[i].getDir()) {
		case 0:
			playerBullets_[i].setPosY(playerBullets_[i].getPosY() - 1);
			break;
		case 1:
			playerBullets_[i].setPosY(playerBullets_[i].getPosY() + 1);
			break;
		case 2:
			playerBullets_[i].setPosY(playerBullets_[i].getPosY() - 1);
			break;
		case 3:
			playerBullets_[i].setPosX(playerBullets_[i].getPosX() - 1);
			break;
		case 4:
			playerBullets_[i].setPosX(playerBullets_[i].getPosX() + 1);
			break;
		default:
			break;
		}
		bool isBorder = (playerBullets_[i].getPosX() == 0 || playerBullets_[i].getPosX() == Constants::WIDTH - 1 ||
			playerBullets_[i].getPosY() == 0 || playerBullets_[i].getPosY() == Constants::HEIGHT - 1);
		bool isGold = (playerBullets_[i].getPosX() == Constants::posGoldX && playerBullets_[i].getPosY() == Constants::posGoldY);
		if (isBorder || isGold) {
			playerBullets_.erase(playerBullets_.begin() + i);
		}
		else {
			bool isEnemyDestroyed = false;
			for (int j = 0; j < enemies_.size(); j++) {
				if (i < playerBullets_.size()) {
					bool isEnemy = (playerBullets_[i].getPosX() == enemies_[j].getPosX() &&
						playerBullets_[i].getPosY() == enemies_[j].getPosY());
					if (isEnemy) {
						playerBullets_.erase(playerBullets_.begin() + i);
						enemies_.erase(enemies_.begin() + j);
						j == enemies_.size() - 1;
						tank_.setScore(tank_.getScore()+10);
						isEnemyDestroyed = true;
					}
				}
			}
			if (!isEnemyDestroyed) {
				bool isFortress = false;
				for (int j = 0; j < fortress_.size(); j++) {
					if (i < playerBullets_.size()) {
						bool isFortressTaget = (playerBullets_[i].getPosX() == fortress_[j].getPosX() &&
							playerBullets_[i].getPosY() == fortress_[j].getPosY());
						if (isFortressTaget) {
							playerBullets_.erase(playerBullets_.begin() + i);
							j == fortress_.size() - 1;
							isFortress = true;
						}
					}
				}
				if (!isFortress) {
					for (int j = 0; j < walls_.size(); j++) {
						for (int k = 0; k < walls_[j].getLength(); k++) {
							if (i < playerBullets_.size()) {
								bool isDestroyBlock = (playerBullets_[i].getPosX() == walls_[j][k].getPosX() &&
									playerBullets_[i].getPosY() == walls_[j][k].getPosY());
								if (isDestroyBlock) {
									playerBullets_.erase(playerBullets_.begin() + i);
									walls_[j].destroyBlock(k);
									k = walls_[j].getLength() - 1;
									j = walls_.size() - 1;
								}
							}
						}
					}
				}
			}
		}
	}
    }

